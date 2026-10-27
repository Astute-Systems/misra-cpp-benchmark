// MISRA C++:2023 Rule 26.3.1 (Advisory)
// std::vector should not be specialized with bool
//
// Example 1: vector<bool>

#include <vector>

// BEGIN violation
std::vector<bool> flags() {
    return std::vector<bool>(8);
}
// END violation

// BEGIN compliant
#include <cstdint>

std::vector<std::uint8_t> byte_flags() {
    return std::vector<std::uint8_t>(8);
}
// END compliant
