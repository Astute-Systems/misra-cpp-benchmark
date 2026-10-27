// MISRA C++:2023 Rule 25.5.2 (Mandatory)
// The pointers returned by the C++ Standard Library functions localeconv, getenv, setlocale or strerror must only be used as if they have pointer to const-qualified type
//
// Example 2: Writing through the pointer returned by strerror

#include <cstring>

// BEGIN violation
void modify_error_text() {
    char* text = std::strerror(1);
    text[0] = 'x';
}
// END violation

// BEGIN compliant
char read_error_text() {
    const char* text = std::strerror(1);
    return text[0];
}
// END compliant
