// MISRA C++:2023 Rule 24.5.1 (Required)
// The character handling functions from <cctype> and <cwctype> shall not be used
//
// Example 2: toupper and tolower

#include <cctype>

// BEGIN violation
int to_upper(int c) {
    return std::toupper(c);
}

int to_lower(int c) {
    return std::tolower(c);
}
// END violation

// BEGIN compliant
char to_x(bool upper) {
    return upper ? 'X' : 'x';
}
// END compliant
