// MISRA C++:2023 Rule 7.0.5 (Required)
// Integral promotion and the usual arithmetic conversions shall not change the signedness or the type category of an operand
//
// Example 2: Narrow unsigned operands promoted to signed int

#include <cstdint>

// BEGIN violation
std::uint32_t promoted_product(std::uint16_t x) {
    auto y = x * x;
    return static_cast<std::uint32_t>(y);
}
// END violation

// BEGIN compliant
std::uint32_t widened_product(std::uint16_t x) {
    std::uint32_t wide = x;
    return wide * wide;
}
// END compliant
