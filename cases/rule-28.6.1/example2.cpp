// MISRA C++:2023 Rule 28.6.1 (Required)
// The argument to std::move shall be a non-const lvalue
//
// Example 2: std::move of a prvalue

#include <string>
#include <utility>

// BEGIN violation
std::string move_temporary() {
    return std::move(std::string("text"));
}
// END violation

// BEGIN compliant
std::string return_temporary() {
    return std::string("text");
}
// END compliant
