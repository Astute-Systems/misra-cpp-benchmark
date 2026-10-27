// MISRA C++:2023 Rule 25.5.1 (Required)
// The setlocale and std::locale::global functions shall not be called
//
// Example 2: std::locale::global

#include <locale>

// BEGIN violation
void set_global_locale() {
    std::locale::global(std::locale::classic());
}
// END violation

// BEGIN compliant
std::locale get_global_locale() {
    return std::locale();
}
// END compliant
