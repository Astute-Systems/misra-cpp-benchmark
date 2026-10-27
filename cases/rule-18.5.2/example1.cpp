// MISRA C++:2023 Rule 18.5.2 (Advisory)
// Program-terminating functions should not be used
//
// Example 1: Call to abort

#include <cstdlib>

// BEGIN violation
void call_abort() {
    std::abort();
}
// END violation

// BEGIN compliant
int report_error() {
    return 1;
}
// END compliant
