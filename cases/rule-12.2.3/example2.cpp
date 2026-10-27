// MISRA C++:2023 Rule 12.2.3 (Required)
// A named bit-field with signed integer type shall not have a length of one bit
//
// Example 2: Signed one-bit field of a fixed-width type

#include <cstdint>

// BEGIN violation
struct SignedByteBit {
    std::int8_t bit : 1;
};
// END violation

// BEGIN compliant
struct SignedTwoBits {
    std::int8_t bits : 2;
};
// END compliant
