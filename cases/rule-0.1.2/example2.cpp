// MISRA C++:2023 Rule 0.1.2 (Required)
// The value returned by a function shall be used
//
// Example 2: Return value of a standard library function discarded

#include <cstdlib>

// BEGIN violation
void discards_abs(int v) {
    std::abs(v);
}
// END violation

// BEGIN compliant
int keeps_abs(int v) {
    return std::abs(v);
}
// END compliant
