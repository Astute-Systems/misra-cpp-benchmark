// MISRA C++:2023 Rule 21.2.1 (Required)
// The library functions atof, atoi, atol and atoll from <cstdlib> shall not be used
//
// Example 2: atof and atol

#include <cstdlib>

// BEGIN violation
double parse_with_atof(const char* s) {
    return std::atof(s);
}

long parse_with_atol(const char* s) {
    return std::atol(s);
}
// END violation

// BEGIN compliant
double parse_with_strtod(const char* s) {
    return std::strtod(s, nullptr);
}
// END compliant
