// MISRA C++:2023 Rule 25.5.2 (Mandatory)
// The pointers returned by the C++ Standard Library functions localeconv, getenv, setlocale or strerror must only be used as if they have pointer to const-qualified type
//
// Example 1: Writing through the pointer returned by getenv

#include <cstdlib>

// BEGIN violation
void modify_environment_value() {
    char* value = std::getenv("HOME");
    if (value != nullptr) {
        value[0] = 'x';
    }
}
// END violation

// BEGIN compliant
char read_environment_value() {
    const char* value = std::getenv("HOME");
    if (value != nullptr) {
        return value[0];
    }
    return '\0';
}
// END compliant
