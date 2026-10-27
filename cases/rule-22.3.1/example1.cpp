// MISRA C++:2023 Rule 22.3.1 (Required)
// The assert macro shall not be used with a constant-expression
//
// Example 1: assert with a constant expression

#include <cassert>

// BEGIN violation
void assert_constant() {
    assert(sizeof(int) >= 2);
}
// END violation

// BEGIN compliant
void assert_runtime(int v) {
    assert(v >= 0);
}

static_assert(sizeof(int) >= 2, "int is too small");
// END compliant
