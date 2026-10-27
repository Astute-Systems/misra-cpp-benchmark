# misra-cpp-benchmark

A corpus of small, self-contained C++17 examples for benchmarking static
analysers against **MISRA C++:2023**.

* **179 guidelines**, every one with **one or more examples** (328 in total).
* Each example contains a **violation** and, where a compliant form exists, a
  matching **compliant** version, so a checker is scored both on what it finds
  and on what it wrongly reports.
* **No dependencies.** Standard library only, no build system required.
* **Works on Linux, macOS and Windows.** The only requirements are Python 3.7+
  and a C++17 compiler on `PATH`.
* Ships a scoring script that reads any SARIF 2.1.0 file.

> **Not affiliated with MISRA.** MISRA is a registered trademark of HORIBA MIRA
> Limited. This repository does not contain the standard. Guideline numbers and
> their short titles are listed only so that results can be mapped, and every
> example is original code written for this project. Buy the standard from
> [misra.org.uk](https://misra.org.uk/) to read what each guideline actually
> requires.
>
> The examples were written from the guideline titles and general knowledge of
> the C++ language, **not** from a licensed copy of the standard. Where the
> exact boundary of a guideline is open to interpretation, treat the example as
> one reasonable reading and review it against your own licensed copy. Issues
> and corrections are welcome.

## Quick start

```bash
git clone <this repository>
cd misra-cpp-benchmark

# 1. Create compile_commands.json for this machine
python3 tools/gen_compile_commands.py

# 2. Point your checker at it
your-checker --compile-commands compile_commands.json ...
```

On Windows use `py tools\gen_compile_commands.py` (or `python`). The compiler is
taken from `$CXX`, otherwise the first of `c++`, `clang++`, `g++` found on
`PATH` (`clang++`, `g++`, `c++` on Windows). Override it with
`--compiler`:

```bash
python3 tools/gen_compile_commands.py --compiler clang++ --std c++17
```

`compile_commands.json` holds absolute paths for the machine that generated it,
so it is not committed. Regenerate it whenever you move the checkout.

CMake users can get the same database without Python:

```bash
cmake -S . -B build        # writes build/compile_commands.json
```

## Scoring a checker

`tools/benchmark.py` runs your checker (or reads its SARIF output) and compares
the findings with the regions marked in the sources.

```bash
# Run a checker and score it. {compile_commands} and {sarif} are substituted.
python3 tools/benchmark.py \
    --run "themis-lint --compile-commands {compile_commands} --quiet --sarif {sarif}" \
    --details

# Or score a SARIF file you already have
python3 tools/benchmark.py --sarif results.sarif --details --json result.json --markdown result.md
```

Locations in the SARIF file are resolved against the repository root, so run
your checker from there (the script does this for `--run`).

The result is reported per category (Mandatory, Required, Advisory) and per
chapter:

| Measure | Meaning |
| --- | --- |
| Detected | Violation examples where the checker reported the guideline inside the `violation` region. |
| Guidelines fully detected | Guidelines for which **every** violation example was detected. |
| False alarms | Compliant examples where the checker reported the same guideline inside the `compliant` region. |

Only findings for the guideline an example is about are scored. Other findings
in the same file are ignored, because examples are small and will often break
unrelated guidelines (for instance every free function breaks "global
declarations should be avoided"). Findings that fall outside every region are
counted for information only. Suppressed findings are ignored.

### Mapping your checker's rule ids to guideline numbers

The script finds the guideline number for each result in this order:

1. `--rule-map FILE`, a JSON object such as `{"my-tool-0042": "8.2.2"}`
2. `properties.guidelines` on the SARIF rule descriptor
3. `properties.misraReference` on the result
4. a number such as `8.2.2`, `Rule 8.2.2`, `rule-8-2-2` or `misra-c++2023-8.2.2`
   in the rule id, name or tags

Checkers that follow none of these conventions need a `--rule-map`.

## Layout

```text
cases/
  rule-0.0.1/              one directory per guideline (dir-X.Y.Z for directives)
    example1.cpp           one example
    example2.cpp           another example
  rule-6.2.1/
    example1.cpp           examples may span several files...
    example1_b.cpp         ...which together form one program
  ...
docs/RULES.md              index of every guideline with its examples
rules.json                 guideline number, category and title
tools/                     Python helpers (standard library only)
CMakeLists.txt             optional alternative to gen_compile_commands.py
```

Directory names use the guideline number as printed by MISRA, for example
`cases/rule-8.2.2/`. The browsable list is [docs/RULES.md](docs/RULES.md).

### Anatomy of an example

```cpp
// MISRA C++:2023 Rule 5.13.3 (Required)
// Octal constants shall not be used
//
// Example 1: Octal integer literal

// BEGIN violation
int file_mode() {
    return 0755;
}
// END violation

// BEGIN compliant
int file_mode_decimal() {
    return 493;
}
// END compliant
```

* The header names the guideline and describes the example.
* Code between `// BEGIN violation` and `// END violation` breaks the guideline.
  The checker is expected to report it somewhere in that region.
* Code between `// BEGIN compliant` and `// END compliant` is the corrected
  form. The checker is expected to stay silent about the guideline there.
* Some examples contain only a violation region or only a compliant region. This
  happens when the compliant form needs a different file layout (a program's
  `main`, of which a translation unit can have only one, or the pair of sized
  and unsized `operator delete`). The compliant form is then a separate example
  whose description says "compliant counterpart".
* Everything outside the regions is scaffolding (includes, declarations the
  example needs) and is never scored.

Every example file name starts with `exampleN`. All files that share the same
`N` inside one directory belong to the same example.

## Notes for tool authors

* **Every example is one program.** `gen_compile_commands.py` records an object
  path of the form `obj/CMakeFiles/<case>-example<N>.dir/<file>.o`, the layout
  CMake produces for a target. Checkers that compare translation units of the
  same target (for the one-definition rules 6.2.1 to 6.2.4) can use that to
  decide which files belong together. The CMake route gives the same grouping.
* **Everything compiles**, with the exception listed below. Examples are
  compiled with `-std=c++17` and warnings are expected: the violating code often
  triggers compiler warnings by nature. No example needs more than the standard
  library.
* **Not compilable:** two guidelines can only be broken in code that no compiler
  accepts. `cases/rule-19.1.2` closes a conditional in a different file from the
  one that opened it, and the first example of `cases/rule-5.13.7` concatenates
  string literals with two different encoding prefixes. Such files carry a
  `NO-COMPILE:` tag, are left out of `compile_commands.json` and are not scored
  (the benchmark lists them). They remain for tools that read a file directly.
* **Platform dependent:** `cases/rule-5.13.6` is only a violation where `long`
  has 32 bits (Windows, or a 32-bit target), because elsewhere the literal has
  type `long`. The file carries `REQUIRES: long-is-32-bit`; the benchmark scores
  it only on platforms where that holds.
* **Per-file compiler flags:** a line `// COMPILE-FLAGS: -Wno-non-pod-varargs` in
  a source file adds those flags to its entry in `compile_commands.json`. The
  8.2.11 examples use it because Clang refuses to pass a non-trivial class
  through `...` unless that diagnostic is switched off.
* **Compiler extensions:** the examples for rule 4.1.1 rely on a variable-length
  array and on designated initializers in C++17 mode. GCC and Clang accept both.
* **Header names:** the examples for rule 19.2.3 include a file whose name
  contains an apostrophe and one reached through a `//` in the path. Both are
  valid on Linux, macOS and Windows.
* **Line endings:** `.gitattributes` forces LF. Rule 5.7.3 depends on a
  backslash being the last character of a line, so do not convert the files to
  CRLF.

## Checking the corpus

```bash
python3 tools/check_cases.py --compile    # structure, markers, and a syntax-only compile of every file
python3 tools/make_index.py --check       # docs/RULES.md is current
```

`check_cases.py` verifies that every guideline in `rules.json` has at least one
example with a violation region, that markers are balanced, and (with
`--compile`) that every translation unit compiles without errors.

## Adding or changing an example

See [docs/ADDING_EXAMPLES.md](docs/ADDING_EXAMPLES.md).

## Licence

[MIT](LICENSE). The licence covers the code in this repository only. It does
not grant any rights to the MISRA documents.
