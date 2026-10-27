// MISRA C++:2023 Rule 8.18.1 (Mandatory)
// An object or subobject must not be copied to an overlapping object
//
// Example 1: Overlapping memcpy

#include <cstring>

// BEGIN violation
void overlapping_memcpy() {
    char buffer[16] = {};
    std::memcpy(buffer + 1, buffer, 8);
}
// END violation

// BEGIN compliant
void disjoint_memcpy() {
    char buffer[16] = {};
    std::memcpy(buffer + 8, buffer, 8);
}
// END compliant
