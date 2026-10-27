// MISRA C++:2023 Rule 22.3.1 (Required)
// The assert macro shall not be used with a constant-expression
//
// Example 2: assert with a literal false

#include <cassert>

// BEGIN violation
void assert_unreachable() {
    assert(false && "should never get here");
}
// END violation

// BEGIN compliant
void assert_flag(bool ok) {
    assert(ok);
}
// END compliant
