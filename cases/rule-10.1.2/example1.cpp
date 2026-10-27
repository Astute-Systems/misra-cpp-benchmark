// MISRA C++:2023 Rule 10.1.2 (Required)
// The volatile qualifier shall be used appropriately
//
// Example 1: volatile applied to a class type

// BEGIN violation
struct Register {
    int value;
};

volatile Register g_register_block = {0};
// END violation

// BEGIN compliant
#include <cstdint>

volatile std::uint32_t g_register_word = 0U;
// END compliant
