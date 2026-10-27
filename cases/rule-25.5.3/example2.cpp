// MISRA C++:2023 Rule 25.5.3 (Mandatory)
// The pointer returned by the C++ Standard Library functions asctime, ctime, gmtime, localtime, localeconv, getenv, setlocale or strerror must not be used following a subsequent call to the same function
//
// Example 2: Result of localtime used after a second localtime call

#include <ctime>

// BEGIN violation
int use_stale_localtime() {
    std::time_t t = 0;
    std::tm* a = std::localtime(&t);
    std::tm* b = std::localtime(&t);
    return a->tm_year + b->tm_year;
}
// END violation

// BEGIN compliant
int copy_before_next_localtime() {
    std::time_t t = 0;
    int first = std::localtime(&t)->tm_year;
    int second = std::localtime(&t)->tm_year;
    return first + second;
}
// END compliant
