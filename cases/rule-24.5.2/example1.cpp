// MISRA C++:2023 Rule 24.5.2 (Required)
// The C++ Standard Library functions memcpy, memmove, memcmp and memchr from <cstring> shall not be used
//
// Example 1: memcpy and memmove

#include <cstring>

// BEGIN violation
void copy_bytes(void* dst, const void* src) {
    std::memcpy(dst, src, 4);
    std::memmove(dst, src, 4);
}
// END violation

// BEGIN compliant
#include <algorithm>

void copy_ints(const int* src, int* dst) {
    std::copy(src, src + 4, dst);
}
// END compliant
