// MISRA C++:2023 Rule 8.2.7 (Advisory)
// A cast should not convert a pointer type to an integral type
//
// Example 1: Pointer converted to uintptr_t

#include <cstdint>

// BEGIN violation
std::uintptr_t pointer_to_uintptr(const int* p) {
    return reinterpret_cast<std::uintptr_t>(p);
}
// END violation

// BEGIN compliant
const int* pointer_unchanged(const int* p) {
    return p;
}
// END compliant
