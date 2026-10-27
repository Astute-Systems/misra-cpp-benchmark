// MISRA C++:2023 Rule 6.9.2 (Advisory)
// The names of the standard signed integer types and standard unsigned integer types should not be used
//
// Example 1: Built-in integer type names

// BEGIN violation
unsigned long builtin_names(int count) {
    unsigned long total = 0;
    for (int i = 0; i < count; ++i) {
        total += static_cast<unsigned long>(i);
    }
    return total;
}
// END violation

// BEGIN compliant
#include <cstdint>

std::uint64_t fixed_width_names(std::int32_t count) {
    std::uint64_t total = 0;
    for (std::int32_t i = 0; i < count; ++i) {
        total += static_cast<std::uint64_t>(i);
    }
    return total;
}
// END compliant
