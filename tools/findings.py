"""Readers that turn a checker's output into a flat list of findings.

Every reader returns dictionaries with the keys

    path      absolute path of the file the finding is in
    line      1-based line of the finding
    rule      the checker's own rule id (may be empty)
    ids       MISRA C++ guideline numbers the finding refers to, e.g. ["8.2.2"]
    message   the checker's message (may be empty)

Supported formats: sarif, cppcheck-xml, text (GCC/Clang style
"file:line:col: warning: message [rule]"), csv (file,line,rule[,message]) and
json (a list of {"file", "line", "rule", "message"} objects, or an object with
a "findings" list). Standard library only.
"""

import csv
import json
import os
import re
import xml.etree.ElementTree as ET
from pathlib import Path
from urllib.parse import unquote, urlparse
from urllib.request import url2pathname

FORMATS = ("sarif", "cppcheck-xml", "text", "csv", "json")

ID_PATTERNS = [
    re.compile(r"(?:Rule|Dir(?:ective)?)\s+(\d{1,2}\.\d{1,2}\.\d{1,2})", re.I),
    re.compile(r"rule-(\d{1,2})-(\d{1,2})-(\d{1,2})", re.I),
    re.compile(r"misra[-_ ]?c\+\+(?:[-_ ]?2023)?[-:/_ ]+(\d{1,2})[.\-](\d{1,2})[.\-](\d{1,2})", re.I),
    re.compile(r"(?<![\d.])(\d{1,2}\.\d{1,2}\.\d{1,2})(?![\d.])"),
]

TEXT_RE = re.compile(
    r"^(?P<file>.+?):(?P<line>\d+)(?::\d+)?:\s*(?:(?:warning|error|note|style|info|performance|portability)\s*:\s*)?"
    r"(?P<message>.*?)(?:\s*\[(?P<rule>[^\[\]]+)\])?\s*$"
)


def extract_ids(text):
    """MISRA C++ guideline numbers mentioned in a string, in order of appearance."""
    found = []
    for pattern in ID_PATTERNS:
        for match in pattern.finditer(text):
            groups = match.groups()
            ident = groups[0] if len(groups) == 1 else ".".join(groups)
            if ident not in found:
                found.append(ident)
        if found:
            break
    return found


def resolve_ids(rule, message, rule_map, extra=()):
    """Guideline numbers for a finding: the rule map first, then patterns in the rule id, extras, message."""
    if rule in rule_map:
        mapped = rule_map[rule]
        return [mapped] if isinstance(mapped, str) else list(mapped)
    for source in [[rule], *[[e] for e in extra], [message]]:
        ids = []
        for item in source:
            ids += [i for i in extract_ids(str(item or "")) if i not in ids]
        if ids:
            return ids
    return []


def resolve_path(text, srcroot):
    parsed = urlparse(text)
    if parsed.scheme == "file":
        path = Path(url2pathname(unquote(parsed.path)))
    else:
        path = Path(unquote(text))
        if not path.is_absolute():
            path = Path(srcroot) / path
    try:
        return str(path.resolve())
    except OSError:
        return str(path)


def detect_format(path):
    suffix = Path(path).suffix.lower()
    if suffix == ".sarif":
        return "sarif"
    if suffix == ".xml":
        return "cppcheck-xml"
    if suffix == ".csv":
        return "csv"
    if suffix == ".json":
        with open(path, encoding="utf-8") as fh:
            head = fh.read(4096)
        return "sarif" if '"runs"' in head else "json"
    return "text"


def _sarif_ids(result, descriptor, rule_map):
    rule_id = result.get("ruleId", "")
    if rule_id in rule_map:
        return resolve_ids(rule_id, "", rule_map)
    descriptor = descriptor or {}
    properties = descriptor.get("properties", {})
    for source in (
        properties.get("guidelines"),
        [result.get("properties", {}).get("misraReference", "")],
        [rule_id],
        [descriptor.get("name", "")],
        properties.get("tags"),
        [descriptor.get("shortDescription", {}).get("text", "")],
    ):
        if not source:
            continue
        ids = []
        for item in source:
            ids += [i for i in extract_ids(str(item)) if i not in ids]
        if ids:
            return ids
    return []


def read_sarif(path, srcroot, rule_map):
    with open(path, encoding="utf-8") as fh:
        sarif = json.load(fh)
    findings = []
    for run in sarif.get("runs", []):
        descriptors = {d.get("id"): d for d in run.get("tool", {}).get("driver", {}).get("rules", [])}
        for result in run.get("results", []):
            if result.get("kind", "fail") != "fail" or result.get("suppressions"):
                continue
            rule = result.get("ruleId", "")
            ids = _sarif_ids(result, descriptors.get(rule), rule_map)
            message = result.get("message", {}).get("text", "")
            locations = result.get("locations") or [None]
            for location in locations:
                if location is None:
                    findings.append({"path": None, "line": None, "rule": rule, "ids": ids, "message": message})
                    continue
                physical = location.get("physicalLocation", {})
                uri = physical.get("artifactLocation", {}).get("uri")
                line = physical.get("region", {}).get("startLine")
                findings.append({
                    "path": resolve_path(uri, srcroot) if uri else None,
                    "line": line, "rule": rule, "ids": ids, "message": message,
                })
    return findings


def read_cppcheck_xml(path, srcroot, rule_map):
    findings = []
    for error in ET.parse(path).getroot().iter("error"):
        rule = error.get("id", "")
        message = error.get("msg", "") or error.get("verbose", "")
        extra = [value for key, value in error.attrib.items() if key not in ("id", "msg", "verbose", "file0")]
        ids = resolve_ids(rule, message, rule_map, extra)
        locations = list(error.iter("location")) or [None]
        for location in locations:
            if location is None or not location.get("file"):
                findings.append({"path": None, "line": None, "rule": rule, "ids": ids, "message": message})
            else:
                findings.append({
                    "path": resolve_path(location.get("file"), srcroot),
                    "line": int(location.get("line", "0")) or None,
                    "rule": rule, "ids": ids, "message": message,
                })
    return findings


def read_text(path, srcroot, rule_map):
    findings = []
    with open(path, encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            match = TEXT_RE.match(raw.rstrip("\r\n"))
            if not match:
                continue
            rule = (match.group("rule") or "").strip()
            message = match.group("message") or ""
            findings.append({
                "path": resolve_path(match.group("file"), srcroot), "line": int(match.group("line")),
                "rule": rule, "ids": resolve_ids(rule, message, rule_map), "message": message,
            })
    return findings


def _from_rows(rows, srcroot, rule_map):
    findings = []
    for row in rows:
        file_name = row.get("file") or row.get("path")
        line = row.get("line")
        if not file_name or line in (None, ""):
            continue
        rule = str(row.get("rule") or row.get("id") or "")
        message = str(row.get("message") or "")
        extra = [row.get("guideline", "")]
        findings.append({
            "path": resolve_path(str(file_name), srcroot), "line": int(line), "rule": rule,
            "ids": resolve_ids(rule, message, rule_map, extra), "message": message,
        })
    return findings


def read_csv(path, srcroot, rule_map):
    with open(path, encoding="utf-8", newline="") as fh:
        text = fh.read()
    first = text.splitlines()[0].lower() if text.strip() else ""
    if "file" in first and "line" in first:
        rows = list(csv.DictReader(text.splitlines()))
    else:
        rows = [dict(zip(("file", "line", "rule", "message"), r)) for r in csv.reader(text.splitlines())]
    return _from_rows(rows, srcroot, rule_map)


def read_json(path, srcroot, rule_map):
    with open(path, encoding="utf-8") as fh:
        data = json.load(fh)
    rows = data.get("findings", []) if isinstance(data, dict) else data
    return _from_rows(rows, srcroot, rule_map)


READERS = {
    "sarif": read_sarif,
    "cppcheck-xml": read_cppcheck_xml,
    "text": read_text,
    "csv": read_csv,
    "json": read_json,
}


def read_findings(path, fmt, srcroot, rule_map):
    fmt = fmt if fmt and fmt != "auto" else detect_format(path)
    return READERS[fmt](path, srcroot, rule_map)


def normalise(path):
    return os.path.normcase(str(path))
