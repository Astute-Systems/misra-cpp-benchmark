// MISRA C++:2023 Rule 25.5.3 (Mandatory)
// The pointer returned by the C++ Standard Library functions asctime, ctime, gmtime, localtime, localeconv, getenv, setlocale or strerror must not be used following a subsequent call to the same function
//
// Example 1: Result of getenv used after a second getenv call

#include <cstdlib>

// BEGIN violation
char use_stale_getenv() {
    const char* a = std::getenv("A");
    const char* b = std::getenv("B");
    return static_cast<char>(a[0] + b[0]);
}
// END violation

// BEGIN compliant
char use_before_next_getenv() {
    const char* a = std::getenv("A");
    char first = a[0];
    const char* b = std::getenv("B");
    return static_cast<char>(first + b[0]);
}
// END compliant
