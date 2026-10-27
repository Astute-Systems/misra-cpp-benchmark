// MISRA C++:2023 Rule 25.5.1 (Required)
// The setlocale and std::locale::global functions shall not be called
//
// Example 1: setlocale

#include <clocale>

// BEGIN violation
void call_setlocale() {
    std::setlocale(LC_ALL, "C");
}
// END violation

// BEGIN compliant
int locale_category_count() {
    return LC_ALL;
}
// END compliant
