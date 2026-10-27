"""Shared helpers for the benchmark tools. Standard library only."""

import json
import os
import re
import shlex
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CASES = ROOT / "cases"

BEGIN_RE = re.compile(r"^\s*//\s*BEGIN\s+(violation|compliant)\s*$")
END_RE = re.compile(r"^\s*//\s*END\s+(violation|compliant)\s*$")
EXAMPLE_RE = re.compile(r"^example(\d+)(?=$|[_.])")
DESC_RE = re.compile(r"^//\s*Example\s+(\d+):\s*(.*)$")
NO_COMPILE_TAG = "NO-COMPILE:"
FLAGS_RE = re.compile(r"COMPILE-FLAGS:\s*(.+?)\s*$")
SOURCE_SUFFIXES = {".cpp", ".h"}


def load_rules():
    with open(ROOT / "rules.json", encoding="utf-8") as fh:
        return json.load(fh)


def read_lines(path):
    with open(path, encoding="utf-8", newline="") as fh:
        return fh.read().splitlines()


def case_sources(case_dir):
    """All .cpp and .h files below a case directory, sorted."""
    return sorted(p for p in Path(case_dir).rglob("*") if p.suffix in SOURCE_SUFFIXES)


def is_no_compile(path):
    return any(NO_COMPILE_TAG in line for line in read_lines(path))


def compile_flags(path):
    """Extra compiler flags requested by a `// COMPILE-FLAGS: ...` line in a source file."""
    flags = []
    for line in read_lines(path):
        match = FLAGS_RE.search(line)
        if match:
            flags += shlex.split(match.group(1))
    return flags


def translation_units():
    """Every .cpp that is meant to compile, sorted by path."""
    units = []
    for case in sorted(CASES.iterdir()):
        if not case.is_dir():
            continue
        for src in case_sources(case):
            if src.suffix == ".cpp" and not is_no_compile(src):
                units.append(src)
    return units


def example_number(path):
    """Example number from a file name such as example3_b.cpp, or None."""
    match = EXAMPLE_RE.match(Path(path).name)
    return int(match.group(1)) if match else None


def example_descriptions(case_dir):
    """Map example number -> one-line description from the file header."""
    result = {}
    for src in case_sources(case_dir):
        if src.suffix != ".cpp":
            continue
        for line in read_lines(src)[:6]:
            match = DESC_RE.match(line)
            if match:
                result[int(match.group(1))] = match.group(2)
    return result


def parse_regions(path):
    """Return ([(kind, first_line, last_line)], [problems]); lines are 1-based."""
    regions = []
    problems = []
    open_kind = None
    open_line = 0
    for number, line in enumerate(read_lines(path), 1):
        begin = BEGIN_RE.match(line)
        end = END_RE.match(line)
        if begin:
            if open_kind:
                problems.append(f"{path}:{number}: BEGIN {begin.group(1)} inside open {open_kind} region")
            open_kind, open_line = begin.group(1), number
        elif end:
            if open_kind != end.group(1):
                problems.append(f"{path}:{number}: END {end.group(1)} without matching BEGIN")
            else:
                regions.append((open_kind, open_line, number))
            open_kind = None
    if open_kind:
        problems.append(f"{path}:{open_line}: BEGIN {open_kind} is never closed")
    return regions, problems


def find_compiler(requested=None):
    """Locate a C++ compiler; returns an absolute path or None."""
    candidates = []
    if requested:
        candidates.append(requested)
    elif os.environ.get("CXX"):
        candidates.append(os.environ["CXX"])
    elif sys.platform == "win32":
        candidates += ["clang++", "g++", "c++"]
    else:
        candidates += ["c++", "clang++", "g++"]
    for name in candidates:
        found = shutil.which(name)
        if found:
            return found
    return None
