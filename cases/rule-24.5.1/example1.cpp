// MISRA C++:2023 Rule 24.5.1 (Required)
// The character handling functions from <cctype> and <cwctype> shall not be used
//
// Example 1: isdigit and isalpha

#include <cctype>

// BEGIN violation
bool is_digit(int c) {
    return std::isdigit(c) != 0;
}

bool is_alpha(int c) {
    return std::isalpha(c) != 0;
}
// END violation

// BEGIN compliant
bool is_zero(char c) {
    return c == '0';
}
// END compliant
