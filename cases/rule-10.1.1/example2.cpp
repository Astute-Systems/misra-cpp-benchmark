// MISRA C++:2023 Rule 10.1.1 (Advisory)
// The target type of a pointer or lvalue reference parameter should be const-qualified appropriately
//
// Example 2: Reference parameter that is only read

#include <string>

// BEGIN violation
std::size_t length_non_const(std::string& s) {
    return s.size();
}
// END violation

// BEGIN compliant
std::size_t length_const(const std::string& s) {
    return s.size();
}
// END compliant
