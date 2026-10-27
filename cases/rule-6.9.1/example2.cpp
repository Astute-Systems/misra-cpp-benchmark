// MISRA C++:2023 Rule 6.9.1 (Required)
// The same type aliases shall be used in all declarations of the same entity
//
// Example 2: Fixed-width alias and built-in type mixed

#include <cstdint>

std::uint32_t checksum(std::uint32_t seed);

// BEGIN violation
unsigned int checksum(unsigned int seed) {
    return seed;
}
// END violation

// BEGIN compliant
std::uint32_t digest(std::uint32_t seed);

std::uint32_t digest(std::uint32_t seed) {
    return seed;
}
// END compliant
