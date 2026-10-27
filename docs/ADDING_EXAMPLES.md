# Adding or changing an example

## Rules of the corpus

1. **Original code only.** Write every example yourself. Do not copy text or
   code from the MISRA documents or from other proprietary sources.
2. **One idea per example.** An example shows one way of breaking a guideline.
   Add a further `exampleN` for a different way (a different syntax, a
   different type, an indirect form).
3. **Standard C++17 and the standard library only.** No third-party headers,
   no operating-system headers, no compiler intrinsics. Code must compile with
   GCC and Clang on Linux, macOS and Windows.
4. **It must compile.** Warnings are fine, errors are not. If a guideline
   cannot be broken in code that compiles, add the tag `NO-COMPILE:` followed by
   the reason in a comment in the file; the file is then left out of
   `compile_commands.json` and the CMake build, and the benchmark does not score
   it. Use this only when there is no alternative. A compiler diagnostic that
   is an error by default can be switched off for one file with
   `// COMPILE-FLAGS: -Wno-...`. An example that is only a violation on some
   platforms carries `// REQUIRES: long-is-32-bit` (the only requirement the
   scorer knows today).
5. **Keep it small.** Examples are read by people. Aim for under 30 lines.
6. **Make the compliant version compliant for the same guideline.** It does not
   need to be perfect for the other guidelines, but it must not be an arguable
   violation of the one under test. If you are unsure, say so in the example
   description and ask in the pull request.
7. **Avoid the platform.** Do not assume the size of `long`, pointers, or
   `int`, byte order, or a particular standard library. If an example cannot
   avoid it, say so in a comment (see `cases/rule-5.13.6`).

## File layout

```text
cases/rule-8.2.2/
  example1.cpp
  example2.cpp
```

* Directive directories are named `dir-X.Y.Z`, all others `rule-X.Y.Z`.
* Every file name starts with `exampleN`. Additional files of the same example
  use `exampleN_something.cpp` or `exampleN_something.h`, or live in a
  subdirectory with such a name (`inc/example2_inc.h`).
* All `.cpp` files of one example form one program. The compile database gives
  them the same target, so one-definition checks can compare them.
* The directory name is the single source of truth: it must be listed in
  [rules.json](../rules.json).

## Source template

```cpp
// MISRA C++:2023 Rule X.Y.Z (Category)
// <short title of the guideline>
//
// Example N: <what this example shows>

#include <...>        // scaffolding, never scored

// BEGIN violation
...
// END violation

// BEGIN compliant
...
// END compliant
```

The first three lines are the header. `tools/make_index.py` reads the
`Example N:` line for the index, so keep it on one line.

Marker lines must look exactly like `// BEGIN violation`, `// END violation`,
`// BEGIN compliant`, `// END compliant`. Regions may not nest. A file may
contain several regions of each kind.

### Regions and the rules they test

* Put the smallest block that makes the violation visible inside the region,
  including the whole function when the guideline is about the function.
* A finding is matched by its **start line**. A violation region must therefore
  contain the line a checker would reasonably report. For multi-line
  constructs include the whole construct.
* For preprocessor guidelines put the directives inside the region.
* For guidelines about headers put the region in the header and also around the
  `#include` line if the checker may report there.
* If a compliant form needs a different file layout than the violation, for
  example `main`, give it its own example and describe it as the compliant
  counterpart. The checker is then scored only on that example's compliant
  region.

## Checks before sending a change

```bash
python3 tools/check_cases.py --compile    # every guideline covered, markers balanced, everything compiles
python3 tools/make_index.py               # refresh docs/RULES.md
python3 tools/export_manifest.py          # refresh manifest.json
```

Run the checker you care about as well and look at the example from its side:

```bash
python3 tools/gen_compile_commands.py
python3 tools/benchmark.py --run "<your checker command>" --details
```

If your checker reports a guideline in a `compliant` region, decide honestly
whether the checker or the example is wrong. Both happen.

## Adding a guideline

New guidelines (for example in a later edition) go into `rules.json`
(`id`, `kind` = `Rule` or `Dir`, `category`, `title`, `directory`) together with
at least one example. `check_cases.py` fails until both exist.
