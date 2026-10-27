// MISRA C++:2023 Rule 18.5.2 (Advisory)
// Program-terminating functions should not be used
//
// Example 2: Calls to exit and terminate

#include <cstdlib>
#include <exception>

// BEGIN violation
void call_exit() {
    std::exit(1);
}

void call_terminate() {
    std::terminate();
}
// END violation

// BEGIN compliant
int return_status() {
    return 1;
}
// END compliant
