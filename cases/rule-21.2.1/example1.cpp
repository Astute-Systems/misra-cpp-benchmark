// MISRA C++:2023 Rule 21.2.1 (Required)
// The library functions atof, atoi, atol and atoll from <cstdlib> shall not be used
//
// Example 1: atoi

#include <cstdlib>

// BEGIN violation
int parse_with_atoi(const char* s) {
    return std::atoi(s);
}
// END violation

// BEGIN compliant
long parse_with_strtol(const char* s) {
    return std::strtol(s, nullptr, 10);
}
// END compliant
