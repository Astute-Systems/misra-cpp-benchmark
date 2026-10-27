// MISRA C++:2023 Rule 8.2.8 (Required)
// An object pointer type shall not be cast to an integral type other than std::uintptr_t or std::intptr_t
//
// Example 1: Pointer converted to an integer type other than uintptr_t

// BEGIN violation
long long pointer_to_long_long(const int* p) {
    return reinterpret_cast<long long>(p);
}
// END violation

// BEGIN compliant
#include <cstdint>

std::intptr_t pointer_to_intptr(const int* p) {
    return reinterpret_cast<std::intptr_t>(p);
}
// END compliant
