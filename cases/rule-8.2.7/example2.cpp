// MISRA C++:2023 Rule 8.2.7 (Advisory)
// A cast should not convert a pointer type to an integral type
//
// Example 2: Pointer converted to size_t

#include <cstddef>

// BEGIN violation
std::size_t pointer_to_size_t(const int* p) {
    return reinterpret_cast<std::size_t>(p);
}
// END violation

// BEGIN compliant
bool pointer_is_null(const int* p) {
    return p == nullptr;
}
// END compliant
