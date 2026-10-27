// MISRA C++:2023 Rule 21.2.3 (Required)
// The library function system from <cstdlib> shall not be used
//
// Example 1: system

#include <cstdlib>

// BEGIN violation
int run_command() {
    return std::system("true");
}
// END violation

// BEGIN compliant
int no_command() {
    return 0;
}
// END compliant
