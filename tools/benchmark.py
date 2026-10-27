#!/usr/bin/env python3
"""Score a MISRA C++ checker against the examples in cases/.

The checker is run (or its SARIF 2.1.0 output is read) and every finding is
matched against the BEGIN/END regions in the example sources:

  * a finding for the guideline under test inside a "violation" region is a
    detection,
  * a finding for the guideline under test inside a "compliant" region is a
    false alarm.

Findings of other guidelines are not scored, and findings outside every region
are only counted for information.

Examples:

    # run a tool and score it
    python3 tools/benchmark.py --run "themis-lint --compile-commands {compile_commands} --quiet --sarif {sarif}"

    # score a SARIF file produced earlier
    python3 tools/benchmark.py --sarif results.sarif --details
"""

import argparse
import json
import os
import re
import shlex
import subprocess
import sys
import tempfile
from collections import defaultdict
from pathlib import Path
from urllib.parse import unquote, urlparse
from urllib.request import url2pathname

sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402
import gen_compile_commands  # noqa: E402

ID_PATTERNS = [
    re.compile(r"(?:Rule|Dir(?:ective)?)\s+(\d{1,2}\.\d{1,2}\.\d{1,2})", re.I),
    re.compile(r"rule-(\d{1,2})-(\d{1,2})-(\d{1,2})", re.I),
    re.compile(r"misra[-_ ]?c\+\+(?:[-_ ]?2023)?[-:/_ ]+(\d{1,2})[.\-](\d{1,2})[.\-](\d{1,2})", re.I),
    re.compile(r"(?<![\d.])(\d{1,2}\.\d{1,2}\.\d{1,2})(?![\d.])"),
]


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


def guideline_ids(result, descriptor, rule_map):
    """Guideline numbers a SARIF result refers to."""
    rule_id = result.get("ruleId", "")
    if rule_id in rule_map:
        mapped = rule_map[rule_id]
        return [mapped] if isinstance(mapped, str) else list(mapped)
    for source in (
        (descriptor or {}).get("properties", {}).get("guidelines"),
        [result.get("properties", {}).get("misraReference", "")],
        [rule_id],
        [(descriptor or {}).get("name", "")],
        (descriptor or {}).get("properties", {}).get("tags"),
        [(descriptor or {}).get("shortDescription", {}).get("text", "")],
    ):
        if not source:
            continue
        ids = []
        for item in source:
            ids += [i for i in extract_ids(str(item)) if i not in ids]
        if ids:
            return ids
    return []


def resolve_location(uri, srcroot):
    parsed = urlparse(uri)
    if parsed.scheme == "file":
        path = Path(url2pathname(unquote(parsed.path)))
    else:
        path = Path(unquote(uri))
        if not path.is_absolute():
            path = srcroot / path
    try:
        return path.resolve()
    except OSError:
        return path


def norm(path):
    return os.path.normcase(str(path))


def load_corpus():
    """Return (examples, file_index).

    examples: {(rule_id, number): {...}}
    file_index: {normalised path: (rule_id, number, [regions])}
    """
    examples = {}
    file_index = {}
    for rule in common.load_rules():
        case = common.CASES / rule["directory"]
        descriptions = common.example_descriptions(case)
        for src in common.case_sources(case):
            number = common.example_number(src)
            if number is None:
                continue
            regions, _ = common.parse_regions(src)
            key = (rule["id"], number)
            example = examples.setdefault(key, {
                "rule": rule["id"], "number": number, "category": rule["category"],
                "description": descriptions.get(number, ""), "violation_regions": 0,
                "compliant_regions": 0, "violation_hits": 0, "compliant_hits": 0,
            })
            for kind, _, _ in regions:
                example[f"{kind}_regions"] += 1
            file_index[norm(src.resolve())] = (rule["id"], number, regions)
    return examples, file_index


def score(sarif, srcroot, rule_map):
    examples, file_index = load_corpus()
    reported_rules = set()
    outside = defaultdict(int)
    total_findings = 0

    for run in sarif.get("runs", []):
        descriptors = {d.get("id"): d for d in run.get("tool", {}).get("driver", {}).get("rules", [])}
        for result in run.get("results", []):
            if result.get("kind", "fail") != "fail" or result.get("suppressions"):
                continue
            total_findings += 1
            ids = guideline_ids(result, descriptors.get(result.get("ruleId")), rule_map)
            reported_rules.update(ids)
            for location in result.get("locations", []):
                physical = location.get("physicalLocation", {})
                uri = physical.get("artifactLocation", {}).get("uri")
                line = physical.get("region", {}).get("startLine")
                if not uri or line is None:
                    continue
                entry = file_index.get(norm(resolve_location(uri, srcroot)))
                if entry is None:
                    continue
                rule_id, number, regions = entry
                if rule_id not in ids:
                    continue
                kinds = {kind for kind, first, last in regions if first <= line <= last}
                if not kinds:
                    outside[rule_id] += 1
                for kind in kinds:
                    examples[(rule_id, number)][f"{kind}_hits"] += 1
    return examples, reported_rules, dict(outside), total_findings


def percent(part, whole):
    return 100.0 * part / whole if whole else 0.0


def summarise(examples, rules):
    rule_info = {r["id"]: r for r in rules}
    per_rule = {}
    for (rule_id, _), ex in sorted(examples.items(), key=lambda kv: (kv[0][0], kv[0][1])):
        info = per_rule.setdefault(rule_id, {
            "id": rule_id, "title": rule_info[rule_id]["title"], "category": ex["category"],
            "violation_examples": 0, "detected": 0, "compliant_examples": 0, "false_alarms": 0,
            "missed_examples": [], "false_alarm_examples": [],
        })
        if ex["violation_regions"]:
            info["violation_examples"] += 1
            if ex["violation_hits"]:
                info["detected"] += 1
            else:
                info["missed_examples"].append(ex["number"])
        if ex["compliant_regions"]:
            info["compliant_examples"] += 1
            if ex["compliant_hits"]:
                info["false_alarms"] += 1
                info["false_alarm_examples"].append(ex["number"])
    for info in per_rule.values():
        if info["detected"] == 0:
            info["status"] = "missed"
        elif info["detected"] == info["violation_examples"]:
            info["status"] = "detected"
        else:
            info["status"] = "partial"
    return per_rule


def aggregate(per_rule, key):
    groups = defaultdict(lambda: {"rules": 0, "detected_rules": 0, "examples": 0, "detected": 0,
                                  "compliant": 0, "false_alarms": 0})
    for info in per_rule.values():
        group = groups[key(info)]
        group["rules"] += 1
        group["detected_rules"] += info["status"] == "detected"
        group["examples"] += info["violation_examples"]
        group["detected"] += info["detected"]
        group["compliant"] += info["compliant_examples"]
        group["false_alarms"] += info["false_alarms"]
    return groups


def format_row(name, g):
    return (f"  {name:<12} {g['detected']:>4}/{g['examples']:<4} {percent(g['detected'], g['examples']):6.1f}%"
            f"   rules {g['detected_rules']:>3}/{g['rules']:<3}"
            f"   false alarms {g['false_alarms']:>3}/{g['compliant']:<3} {percent(g['false_alarms'], g['compliant']):5.1f}%")


def render_text(per_rule, reported, outside, total_findings, details):
    lines = []
    total = aggregate(per_rule, lambda _: "all")["all"]
    lines.append(f"Findings read: {total_findings}   guidelines reported at least once: "
                 f"{len(reported & set(per_rule))}/{len(per_rule)}")
    lines.append("")
    lines.append("                 detected (violation examples)     guidelines fully detected   false alarms (compliant examples)")
    lines.append(format_row("TOTAL", total))
    lines.append("")
    lines.append("By category")
    for name, group in sorted(aggregate(per_rule, lambda i: i["category"]).items()):
        lines.append(format_row(name, group))
    lines.append("")
    lines.append("By chapter")
    chapters = aggregate(per_rule, lambda i: int(i["id"].split(".")[0]))
    for chapter, group in sorted(chapters.items()):
        lines.append(format_row(f"chapter {chapter}", group))
    if outside:
        lines.append("")
        lines.append(f"Findings for the guideline under test outside every region (not scored): "
                     f"{sum(outside.values())}")
    if details:
        missed = [i for i in per_rule.values() if i["status"] != "detected"]
        lines.append("")
        lines.append(f"Guidelines not fully detected: {len(missed)}")
        for info in sorted(missed, key=lambda i: [int(p) for p in i["id"].split(".")]):
            lines.append(f"  {info['id']:<8} {info['status']:<8} missed examples "
                         f"{info['missed_examples']}  {info['title'][:70]}")
        alarms = [i for i in per_rule.values() if i["false_alarms"]]
        lines.append("")
        lines.append(f"Guidelines with false alarms: {len(alarms)}")
        for info in sorted(alarms, key=lambda i: [int(p) for p in i["id"].split(".")]):
            lines.append(f"  {info['id']:<8} compliant examples {info['false_alarm_examples']}  "
                         f"{info['title'][:70]}")
    return "\n".join(lines)


def render_markdown(per_rule, total_findings):
    total = aggregate(per_rule, lambda _: "all")["all"]
    out = ["# Benchmark result", "",
           f"* Findings read: {total_findings}",
           f"* Violation examples detected: {total['detected']}/{total['examples']} "
           f"({percent(total['detected'], total['examples']):.1f}%)",
           f"* Guidelines fully detected: {total['detected_rules']}/{total['rules']}",
           f"* False alarms on compliant examples: {total['false_alarms']}/{total['compliant']}",
           "", "| Guideline | Category | Status | Detected | False alarms | Title |",
           "| --- | --- | --- | --- | --- | --- |"]
    for info in sorted(per_rule.values(), key=lambda i: [int(p) for p in i["id"].split(".")]):
        out.append(f"| {info['id']} | {info['category']} | {info['status']} | "
                   f"{info['detected']}/{info['violation_examples']} | "
                   f"{info['false_alarms']}/{info['compliant_examples']} | {info['title']} |")
    return "\n".join(out) + "\n"


def run_tool(command, compile_commands, sarif_path):
    if not Path(compile_commands).exists():
        print("compile_commands.json not found; generating it first", file=sys.stderr)
        if gen_compile_commands.main(["--output", str(compile_commands)]) != 0:
            raise SystemExit(1)
    expanded = command.format(compile_commands=compile_commands, sarif=sarif_path, root=common.ROOT)
    argv = shlex.split(expanded, posix=(os.name != "nt"))
    print(f"running: {expanded}", file=sys.stderr)
    done = subprocess.run(argv, cwd=str(common.ROOT))
    if done.returncode != 0:
        print(f"warning: tool exited with status {done.returncode}", file=sys.stderr)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0],
                                     formatter_class=argparse.RawDescriptionHelpFormatter,
                                     epilog=__doc__.split("\n", 2)[2])
    parser.add_argument("--run", metavar="COMMAND",
                        help="command that analyses the corpus and writes SARIF; {compile_commands} "
                             "and {sarif} are substituted")
    parser.add_argument("--sarif", metavar="FILE",
                        help="SARIF file to score (written by --run when both are given)")
    parser.add_argument("--compile-commands", default=str(common.ROOT / "compile_commands.json"))
    parser.add_argument("--srcroot", default=str(common.ROOT),
                        help="directory that relative SARIF locations are relative to (default: repo root)")
    parser.add_argument("--rule-map", metavar="FILE",
                        help="JSON object mapping the checker's rule ids to guideline numbers, "
                             "e.g. {\"my-tool-123\": \"8.2.2\"}")
    parser.add_argument("--details", action="store_true", help="list missed guidelines and false alarms")
    parser.add_argument("--json", metavar="FILE", help="write the full result as JSON")
    parser.add_argument("--markdown", metavar="FILE", help="write a Markdown report")
    parser.add_argument("--min-recall", type=float, metavar="PERCENT",
                        help="exit with status 2 when the detection rate is lower than this")
    args = parser.parse_args(argv)

    if not args.run and not args.sarif:
        parser.error("give --run COMMAND and/or --sarif FILE")

    temp = None
    sarif_path = args.sarif
    if args.run:
        if not sarif_path:
            temp = tempfile.NamedTemporaryFile(suffix=".sarif", delete=False)
            temp.close()
            sarif_path = temp.name
        run_tool(args.run, args.compile_commands, sarif_path)

    try:
        with open(sarif_path, encoding="utf-8") as fh:
            sarif = json.load(fh)
    except (OSError, ValueError) as exc:
        print(f"error: cannot read SARIF file {sarif_path}: {exc}", file=sys.stderr)
        return 1
    finally:
        if temp is not None:
            try:
                os.unlink(temp.name)
            except OSError:
                pass

    rule_map = {}
    if args.rule_map:
        with open(args.rule_map, encoding="utf-8") as fh:
            rule_map = json.load(fh)

    examples, reported, outside, total_findings = score(sarif, Path(args.srcroot).resolve(), rule_map)
    per_rule = summarise(examples, common.load_rules())

    print(render_text(per_rule, reported, outside, total_findings, args.details))
    total = aggregate(per_rule, lambda _: "all")["all"]

    if args.json:
        with open(args.json, "w", encoding="utf-8", newline="\n") as fh:
            json.dump({"total": total, "guidelines": list(per_rule.values()),
                       "outside_regions": outside}, fh, indent=2)
            fh.write("\n")
    if args.markdown:
        with open(args.markdown, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(render_markdown(per_rule, total_findings))

    if args.min_recall is not None and percent(total["detected"], total["examples"]) < args.min_recall:
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
