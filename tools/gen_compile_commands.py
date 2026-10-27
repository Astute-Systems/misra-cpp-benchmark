#!/usr/bin/env python3
"""Write compile_commands.json for every example in cases/.

The database lists absolute paths for the machine it is generated on, so it is
not committed. Generate it once after cloning:

    python3 tools/gen_compile_commands.py

Works on Linux, macOS and Windows with any Python 3.7+ and needs only a C++
compiler on PATH (used to fill in the "arguments" field).
"""

import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402


def object_path(source):
    """CMake-style object path, one pseudo target per example.

    The files of one example (example2.cpp, example2_b.cpp, ...) are meant to be
    linked into one program. Checkers that compare translation units of the same
    target (ODR rules 6.2.x) recognise the CMakeFiles/<target>.dir/ layout.
    """
    case = source.parent.name
    number = common.example_number(source)
    target = f"{case}-example{number}"
    return common.ROOT / "obj" / "CMakeFiles" / f"{target}.dir" / f"{source.name}.o"


def build_database(compiler, std, extra_args):
    entries = []
    for source in common.translation_units():
        arguments = [compiler, f"-std={std}", "-x", "c++", "-I", str(source.parent)]
        arguments += extra_args
        arguments += common.compile_flags(source)
        arguments += ["-o", str(object_path(source)), "-c", str(source)]
        entries.append({
            "directory": str(common.ROOT),
            "file": str(source),
            "arguments": arguments,
        })
    return entries


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--compiler", help="C++ compiler (default: $CXX, then c++/clang++/g++)")
    parser.add_argument("--std", default="c++17", help="language standard (default: c++17)")
    parser.add_argument("--extra-arg", action="append", default=[], metavar="ARG",
                        help="extra compiler argument, repeatable (e.g. --extra-arg=-m32)")
    parser.add_argument("--output", default=str(common.ROOT / "compile_commands.json"),
                        help="output path (default: ./compile_commands.json in the repo root)")
    args = parser.parse_args(argv)

    compiler = common.find_compiler(args.compiler)
    if compiler is None:
        print("error: no C++ compiler found; pass --compiler or set CXX", file=sys.stderr)
        return 1

    entries = build_database(compiler, args.std, args.extra_arg)
    output = Path(args.output)
    with open(output, "w", encoding="utf-8", newline="\n") as fh:
        json.dump(entries, fh, indent=2)
        fh.write("\n")
    print(f"wrote {len(entries)} entries to {output}")
    print(f"compiler: {compiler}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
