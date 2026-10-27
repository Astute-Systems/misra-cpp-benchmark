// MISRA C++:2023 Rule 21.6.1 (Advisory)
// Dynamic memory should not be used
//
// Example 2: Allocation with malloc

#include <cstdlib>

// BEGIN violation
void* allocate_with_malloc() {
    return std::malloc(16);
}
// END violation

// BEGIN compliant
int static_storage() {
    static int buffer[4] = {};
    return buffer[0];
}
// END compliant
