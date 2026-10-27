// MISRA C++:2023 Rule 11.3.1 (Advisory)
// Variables of array type should not be declared
//
// Example 2: Array member

// BEGIN violation
struct Message {
    char name[16];
};
// END violation

// BEGIN compliant
#include <array>

struct SafeMessage {
    std::array<char, 16> name;
};
// END compliant
