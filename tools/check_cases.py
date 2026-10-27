#!/usr/bin/env python3
"""Validate the example corpus.

Checks that

  * every guideline in rules.json has a directory with at least one example
    that contains a violation region,
  * no directory exists that rules.json does not know about,
  * BEGIN/END markers are balanced in every file,
  * (with --compile) every translation unit compiles without errors.

Exit status is 0 when everything passes, 1 otherwise.
"""

import argparse
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402


def check_structure(rules):
    problems = []
    known = {r["directory"] for r in rules}
    for case in sorted(common.CASES.iterdir()):
        if case.is_dir() and case.name not in known:
            problems.append(f"{case}: directory is not listed in rules.json")

    example_count = 0
    for rule in rules:
        case = common.CASES / rule["directory"]
        if not case.is_dir():
            problems.append(f"{rule['id']}: missing directory {case}")
            continue
        examples = {}
        for src in common.case_sources(case):
            regions, marker_problems = common.parse_regions(src)
            problems += marker_problems
            number = common.example_number(src)
            if number is None:
                if src.suffix == ".cpp":
                    problems.append(f"{src}: .cpp file name must start with exampleN")
                continue
            examples.setdefault(number, []).extend(kind for kind, _, _ in regions)
        example_count += len(examples)
        if not any("violation" in kinds for kinds in examples.values()):
            problems.append(f"{rule['id']}: no example contains a violation region")
        for number, kinds in sorted(examples.items()):
            if not kinds:
                problems.append(f"{case}: example{number} has no BEGIN/END regions")
    return problems, example_count


def compile_one(args):
    compiler, std, source = args
    command = [compiler, f"-std={std}", "-x", "c++", "-fsyntax-only",
               "-I", str(source.parent), str(source)]
    done = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                          universal_newlines=True)
    return source, done.returncode, done.stdout


def check_compile(compiler, std, jobs):
    units = common.translation_units()
    failures = []
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for source, code, output in pool.map(compile_one, [(compiler, std, u) for u in units]):
            if code != 0:
                failures.append(f"{source}: compile failed\n{output.rstrip()}")
    return failures, len(units)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--compile", action="store_true",
                        help="also compile every translation unit with -fsyntax-only")
    parser.add_argument("--compiler", help="C++ compiler (default: $CXX, then c++/clang++/g++)")
    parser.add_argument("--std", default="c++17", help="language standard (default: c++17)")
    parser.add_argument("-j", "--jobs", type=int, default=4, help="parallel compiles (default: 4)")
    args = parser.parse_args(argv)

    rules = common.load_rules()
    problems, example_count = check_structure(rules)
    print(f"{len(rules)} guidelines, {example_count} examples")

    if args.compile:
        compiler = common.find_compiler(args.compiler)
        if compiler is None:
            print("error: no C++ compiler found; pass --compiler or set CXX", file=sys.stderr)
            return 1
        failures, units = check_compile(compiler, args.std, args.jobs)
        print(f"compiled {units} translation units with {compiler}")
        problems += failures

    for problem in problems:
        print(problem, file=sys.stderr)
    if problems:
        print(f"FAILED: {len(problems)} problem(s)", file=sys.stderr)
        return 1
    print("OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
