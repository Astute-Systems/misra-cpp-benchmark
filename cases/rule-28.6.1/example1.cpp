// MISRA C++:2023 Rule 28.6.1 (Required)
// The argument to std::move shall be a non-const lvalue
//
// Example 1: std::move of a const object

#include <string>
#include <utility>

// BEGIN violation
std::string move_const() {
    const std::string s("text");
    return std::move(s);
}
// END violation

// BEGIN compliant
std::string move_non_const() {
    std::string s("text");
    return std::move(s);
}
// END compliant
