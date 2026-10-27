// MISRA C++:2023 Rule 11.3.1 (Advisory)
// Variables of array type should not be declared
//
// Example 1: Local array

// BEGIN violation
int local_array() {
    int buffer[8] = {};
    return buffer[0];
}
// END violation

// BEGIN compliant
#include <array>

int std_array() {
    std::array<int, 8> buffer{};
    return buffer[0];
}
// END compliant
