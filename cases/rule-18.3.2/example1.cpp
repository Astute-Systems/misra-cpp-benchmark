// MISRA C++:2023 Rule 18.3.2 (Required)
// An exception of class type shall be caught by const reference or reference
//
// Example 1: Handler catches a class by value

#include <exception>

void might_throw();

// BEGIN violation
void catch_by_value() {
    try {
        might_throw();
    } catch (std::exception e) {
        static_cast<void>(e);
    }
}
// END violation

// BEGIN compliant
void catch_by_reference() {
    try {
        might_throw();
    } catch (const std::exception& e) {
        static_cast<void>(e);
    }
}
// END compliant
