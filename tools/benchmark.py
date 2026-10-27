#!/usr/bin/env python3
"""Score a MISRA C++ checker against the examples in cases/.

The checker is run (or its output is read) and every finding is matched against
the BEGIN/END regions in the example sources (see manifest.json):

  * a finding for the guideline under test inside a "violation" region is a
    detection,
  * a finding for the guideline under test inside a "compliant" region is a
    false alarm.

Findings of other guidelines are not scored, and findings outside every region
are only counted for information.

Output formats that can be read: SARIF 2.1.0, cppcheck XML, GCC/Clang style
text, CSV and JSON (see tools/findings.py).

Examples:

    # run a tool that writes SARIF and score it
    python3 tools/benchmark.py --run "mytool --compile-commands {compile_commands} --sarif {output}"

    # score output you already have; the format is detected from the file
    python3 tools/benchmark.py --findings results.sarif --details
    python3 tools/benchmark.py --findings cppcheck.xml --rule-map maps/my-tool.json

    # score only the guidelines the tool claims to implement, and allow findings
    # that are reported a few lines away from the construct
    python3 tools/benchmark.py --findings out.txt --supported supported.txt --tolerance 2
"""

import argparse
import json
import os
import shlex
import struct
import subprocess
import sys
import tempfile
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402
import findings as findings_module  # noqa: E402
import gen_compile_commands  # noqa: E402

RESULT_SCHEMA = 1


def unmet_requirement(requires):
    """Reason why an example cannot be scored on this machine, or None."""
    for name in requires:
        if name == "long-is-32-bit" and struct.calcsize("l") != 4:
            return "needs a 32-bit long (this platform has a 64-bit long)"
    return None


def load_corpus(manifest, only):
    """Return (examples, file_index) built from the manifest.

    examples: {(guideline, number): {...}}
    file_index: {normalised absolute path: (guideline, number, [(kind, first, last)])}
    """
    examples = {}
    file_index = {}
    for guideline in manifest["guidelines"]:
        if only and guideline["id"] not in only:
            continue
        for ex in guideline["examples"]:
            if not ex["compile"]:
                skip = "cannot be compiled, so a compilation database cannot cover it"
            else:
                skip = unmet_requirement(ex["requires"])
            key = (guideline["id"], ex["number"])
            examples[key] = {
                "rule": guideline["id"], "number": ex["number"], "category": guideline["category"],
                "description": ex["description"],
                "violation_regions": sum(1 for r in ex["regions"] if r["kind"] == "violation"),
                "compliant_regions": sum(1 for r in ex["regions"] if r["kind"] == "compliant"),
                "violation_hits": 0, "compliant_hits": 0, "skip": skip,
            }
            for file_entry in ex["files"]:
                index = file_index.setdefault(findings_module.normalise(common.ROOT / file_entry["path"]),
                                              (guideline["id"], ex["number"], []))
                index[2].extend((r["kind"], r["first_line"], r["last_line"])
                                for r in ex["regions"] if r["file"] == file_entry["path"])
    return examples, file_index


def score(manifest, found, only, tolerance):
    examples, file_index = load_corpus(manifest, only)
    reported_rules = set()
    outside = defaultdict(int)
    total_findings = 0

    for finding in found:
        total_findings += 1
        reported_rules.update(finding["ids"])
        if not finding["path"] or finding["line"] is None:
            continue
        entry = file_index.get(findings_module.normalise(finding["path"]))
        if entry is None:
            continue
        rule_id, number, regions = entry
        if rule_id not in finding["ids"]:
            continue
        line = finding["line"]
        kinds = {kind for kind, first, last in regions if first - tolerance <= line <= last + tolerance}
        if not kinds:
            outside[rule_id] += 1
        for kind in kinds:
            examples[(rule_id, number)][f"{kind}_hits"] += 1
    return examples, reported_rules, dict(outside), total_findings


def percent(part, whole):
    return 100.0 * part / whole if whole else 0.0


def summarise(examples, manifest):
    titles = {g["id"]: g["title"] for g in manifest["guidelines"]}
    per_rule = {}
    for (rule_id, _), ex in sorted(examples.items(), key=lambda kv: (kv[0][0], kv[0][1])):
        info = per_rule.setdefault(rule_id, {
            "id": rule_id, "title": titles[rule_id], "category": ex["category"],
            "violation_examples": 0, "detected": 0, "compliant_examples": 0, "false_alarms": 0,
            "missed_examples": [], "false_alarm_examples": [], "skipped_examples": [],
        })
        if ex["skip"]:
            info["skipped_examples"].append({"example": ex["number"], "reason": ex["skip"]})
            continue
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
        if info["violation_examples"] == 0:
            info["status"] = "unscored"
        elif info["detected"] == 0:
            info["status"] = "missed"
        elif info["detected"] == info["violation_examples"]:
            info["status"] = "detected"
        else:
            info["status"] = "partial"
    return per_rule


def aggregate(per_rule, key, restrict=None):
    groups = defaultdict(lambda: {"rules": 0, "detected_rules": 0, "examples": 0, "detected": 0,
                                  "compliant": 0, "false_alarms": 0})
    for info in per_rule.values():
        if info["status"] == "unscored" or (restrict is not None and info["id"] not in restrict):
            continue
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
            f"   false alarms {g['false_alarms']:>3}/{g['compliant']:<3} "
            f"{percent(g['false_alarms'], g['compliant']):5.1f}%")


def guideline_key(info):
    return [int(p) for p in info["id"].split(".")]


def render_text(per_rule, reported, outside, total_findings, details, supported):
    lines = []
    total = aggregate(per_rule, lambda _: "all")["all"]
    lines.append(f"Findings read: {total_findings}   guidelines reported at least once: "
                 f"{len(reported & set(per_rule))}/{len(per_rule)}")
    lines.append("")
    lines.append("                 detected (violation examples)     guidelines fully detected   "
                 "false alarms (compliant examples)")
    lines.append(format_row("TOTAL", total))
    if supported is not None:
        only_supported = aggregate(per_rule, lambda _: "all", supported).get("all")
        lines.append(format_row("SUPPORTED", only_supported) if only_supported
                     else "  SUPPORTED    no scorable guideline in the supported list")
    lines.append("")
    lines.append("By category")
    for name, group in sorted(aggregate(per_rule, lambda i: i["category"]).items()):
        lines.append(format_row(name, group))
    lines.append("")
    lines.append("By chapter")
    chapters = aggregate(per_rule, lambda i: int(i["id"].split(".")[0]))
    for chapter, group in sorted(chapters.items()):
        lines.append(format_row(f"chapter {chapter}", group))
    unscored = sorted((i for i in per_rule.values() if i["status"] == "unscored"), key=guideline_key)
    skipped = [(i["id"], s["example"], s["reason"]) for i in per_rule.values() for s in i["skipped_examples"]]
    if skipped:
        lines.append("")
        lines.append(f"Examples not scored on this machine: {len(skipped)}")
        for rule_id, number, reason in sorted(skipped):
            lines.append(f"  {rule_id} example {number}: {reason}")
    if unscored:
        lines.append("")
        lines.append("Guidelines without a scorable violation example: " + ", ".join(i["id"] for i in unscored))
    if outside:
        lines.append("")
        lines.append(f"Findings for the guideline under test outside every region (not scored): "
                     f"{sum(outside.values())}")
    if details:
        missed = [i for i in per_rule.values() if i["status"] not in ("detected", "unscored")]
        lines.append("")
        lines.append(f"Guidelines not fully detected: {len(missed)}")
        for info in sorted(missed, key=guideline_key):
            lines.append(f"  {info['id']:<8} {info['status']:<8} missed examples "
                         f"{info['missed_examples']}  {info['title'][:70]}")
        alarms = [i for i in per_rule.values() if i["false_alarms"]]
        lines.append("")
        lines.append(f"Guidelines with false alarms: {len(alarms)}")
        for info in sorted(alarms, key=guideline_key):
            lines.append(f"  {info['id']:<8} compliant examples {info['false_alarm_examples']}  "
                         f"{info['title'][:70]}")
    return "\n".join(lines)


def render_markdown(per_rule, total_findings, meta):
    total = aggregate(per_rule, lambda _: "all")["all"]
    heading = "# Benchmark result"
    if meta.get("tool_name"):
        heading += f": {meta['tool_name']} {meta.get('tool_version', '')}".rstrip()
    out = [heading, "",
           f"* Corpus version: {meta['corpus_version']}",
           f"* Findings read: {total_findings}",
           f"* Violation examples detected: {total['detected']}/{total['examples']} "
           f"({percent(total['detected'], total['examples']):.1f}%)",
           f"* Guidelines fully detected: {total['detected_rules']}/{total['rules']}",
           f"* False alarms on compliant examples: {total['false_alarms']}/{total['compliant']}",
           "", "| Guideline | Category | Status | Detected | False alarms | Title |",
           "| --- | --- | --- | --- | --- | --- |"]
    for info in sorted(per_rule.values(), key=guideline_key):
        out.append(f"| {info['id']} | {info['category']} | {info['status']} | "
                   f"{info['detected']}/{info['violation_examples']} | "
                   f"{info['false_alarms']}/{info['compliant_examples']} | {info['title']} |")
    return "\n".join(out) + "\n"


def run_tool(command, compile_commands, output_path, capture_stdout):
    if not Path(compile_commands).exists():
        print("compile_commands.json not found; generating it first", file=sys.stderr)
        if gen_compile_commands.main(["--output", str(compile_commands)]) != 0:
            raise SystemExit(1)
    expanded = command.format(compile_commands=compile_commands, sarif=output_path, output=output_path,
                              root=common.ROOT)
    argv = shlex.split(expanded, posix=(os.name != "nt"))
    print(f"running: {expanded}", file=sys.stderr)
    if capture_stdout:
        with open(output_path, "w", encoding="utf-8") as out:
            done = subprocess.run(argv, cwd=str(common.ROOT), stdout=out)
    else:
        done = subprocess.run(argv, cwd=str(common.ROOT))
    if done.returncode != 0:
        print(f"warning: tool exited with status {done.returncode}", file=sys.stderr)


def read_id_list(value):
    """Guideline numbers from a comma separated string or from a file (one per line, or a JSON list)."""
    if value is None:
        return None
    path = Path(value)
    text = path.read_text(encoding="utf-8") if path.is_file() else value
    text = text.strip()
    if text.startswith("["):
        return set(json.loads(text))
    return {item for item in text.replace(",", "\n").split() if item}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0],
                                     formatter_class=argparse.RawDescriptionHelpFormatter,
                                     epilog=__doc__.split("\n", 2)[2])
    parser.add_argument("--run", metavar="COMMAND",
                        help="command that analyses the corpus; {compile_commands} and {output} (alias {sarif}) "
                             "are substituted. The command writes {output}, or use --capture-stdout")
    parser.add_argument("--capture-stdout", action="store_true",
                        help="write the command's standard output to {output} (for tools that print findings)")
    parser.add_argument("--findings", "--sarif", dest="findings", metavar="FILE",
                        help="findings file to score (written by --run when both are given)")
    parser.add_argument("--format", choices=("auto",) + findings_module.FORMATS, default="auto",
                        help="format of the findings file (default: detect from the file)")
    parser.add_argument("--compile-commands", default=str(common.ROOT / "compile_commands.json"))
    parser.add_argument("--srcroot", default=str(common.ROOT),
                        help="directory that relative paths in the findings are relative to (default: repo root)")
    parser.add_argument("--rule-map", metavar="FILE",
                        help="JSON object mapping the checker's rule ids to guideline numbers, "
                             "e.g. {\"my-tool-123\": \"8.2.2\"}")
    parser.add_argument("--only", metavar="IDS",
                        help="score only these guidelines (comma separated list or file)")
    parser.add_argument("--supported", metavar="IDS",
                        help="guidelines the checker claims to implement (comma separated list, file with one "
                             "number per line, or JSON list); an extra SUPPORTED row is reported for them")
    parser.add_argument("--tolerance", type=int, default=0, metavar="LINES",
                        help="count a finding that is up to LINES lines outside a region as inside it")
    parser.add_argument("--tool-name", help="name recorded in the JSON and Markdown results")
    parser.add_argument("--tool-version", default="", help="version recorded in the JSON and Markdown results")
    parser.add_argument("--details", action="store_true", help="list missed guidelines and false alarms")
    parser.add_argument("--json", metavar="FILE", help="write the full result as JSON")
    parser.add_argument("--markdown", metavar="FILE", help="write a Markdown report")
    parser.add_argument("--min-recall", type=float, metavar="PERCENT",
                        help="exit with status 2 when the detection rate is lower than this")
    args = parser.parse_args(argv)

    if not args.run and not args.findings:
        parser.error("give --run COMMAND and/or --findings FILE")

    temp = None
    findings_path = args.findings
    if args.run:
        if not findings_path:
            temp = tempfile.NamedTemporaryFile(suffix=".out", delete=False)
            temp.close()
            findings_path = temp.name
        run_tool(args.run, args.compile_commands, findings_path, args.capture_stdout)

    rule_map = {}
    if args.rule_map:
        with open(args.rule_map, encoding="utf-8") as fh:
            rule_map = json.load(fh)

    try:
        fmt = args.format
        if fmt == "auto" and temp is not None:
            fmt = "text" if args.capture_stdout else "sarif"
        found = findings_module.read_findings(findings_path, fmt, Path(args.srcroot).resolve(), rule_map)
    except Exception as exc:  # unreadable file, malformed JSON or XML, unsupported layout
        print(f"error: cannot read findings from {findings_path}: {exc}", file=sys.stderr)
        return 1
    finally:
        if temp is not None:
            try:
                os.unlink(temp.name)
            except OSError:
                pass

    manifest = common.build_manifest()
    only = read_id_list(args.only)
    supported = read_id_list(args.supported)
    examples, reported, outside, total_findings = score(manifest, found, only, max(args.tolerance, 0))
    per_rule = summarise(examples, manifest)

    print(render_text(per_rule, reported, outside, total_findings, args.details, supported))
    total = aggregate(per_rule, lambda _: "all")["all"]
    meta = {"corpus_version": manifest["corpus_version"], "tool_name": args.tool_name,
            "tool_version": args.tool_version}

    if args.json:
        result = {
            "schema": RESULT_SCHEMA,
            "corpus_version": manifest["corpus_version"],
            "standard": manifest["standard"],
            "tool": {"name": args.tool_name, "version": args.tool_version},
            "settings": {"tolerance": args.tolerance, "only": sorted(only) if only else None},
            "total": total,
            "supported_total": (aggregate(per_rule, lambda _: "all", supported).get("all")
                                if supported is not None else None),
            "guidelines": list(per_rule.values()),
            "outside_regions": outside,
        }
        with open(args.json, "w", encoding="utf-8", newline="\n") as fh:
            json.dump(result, fh, indent=2)
            fh.write("\n")
    if args.markdown:
        with open(args.markdown, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(render_markdown(per_rule, total_findings, meta))

    if args.min_recall is not None and percent(total["detected"], total["examples"]) < args.min_recall:
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
