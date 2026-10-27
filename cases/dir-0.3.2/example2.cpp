// MISRA C++:2023 Directive 0.3.2 (Required)
// A function call shall not violate the function's preconditions
//
// Example 2: Null pointer passed to a function that requires a valid string

#include <cstring>

// BEGIN violation
std::size_t length_of_null() {
    return std::strlen(nullptr);
}
// END violation

// BEGIN compliant
std::size_t length_of_text() {
    return std::strlen("text");
}
// END compliant
