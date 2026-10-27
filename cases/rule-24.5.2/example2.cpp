// MISRA C++:2023 Rule 24.5.2 (Required)
// The C++ Standard Library functions memcpy, memmove, memcmp and memchr from <cstring> shall not be used
//
// Example 2: memcmp and memchr

#include <cstring>

// BEGIN violation
int compare_bytes(const void* a, const void* b) {
    return std::memcmp(a, b, 4);
}

const void* find_byte(const void* a) {
    return std::memchr(a, 0, 4);
}
// END violation

// BEGIN compliant
#include <algorithm>

bool compare_ints(const int* a, const int* b) {
    return std::equal(a, a + 4, b);
}
// END compliant
