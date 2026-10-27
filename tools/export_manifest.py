#!/usr/bin/env python3
"""Write manifest.json, a machine-readable description of every example.

Tools written in any language can read the manifest instead of parsing the
BEGIN/END markers in the sources. For each guideline it lists the examples, the
files of each example, the line ranges of the violation and compliant regions,
and whether the example can be compiled and needs extra flags or a platform
feature.

    python3 tools/export_manifest.py           # rewrite manifest.json
    python3 tools/export_manifest.py --check   # fail if manifest.json is stale
"""

import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402


def render():
    return json.dumps(common.build_manifest(), indent=2) + "\n"


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--check", action="store_true", help="fail if manifest.json is out of date")
    args = parser.parse_args(argv)

    target = common.ROOT / "manifest.json"
    text = render()
    if args.check:
        current = target.read_text(encoding="utf-8") if target.exists() else ""
        if current != text:
            print("manifest.json is out of date; run python3 tools/export_manifest.py", file=sys.stderr)
            return 1
        print("manifest.json is up to date")
        return 0
    with open(target, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(text)
    print(f"wrote {target}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
