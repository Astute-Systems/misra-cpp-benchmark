// MISRA C++:2023 Rule 21.6.3 (Required)
// Advanced memory management shall not be used
//
// Example 2: nothrow new

#include <new>

// BEGIN violation
int* nothrow_allocate() {
    return new (std::nothrow) int(0);
}
// END violation

// BEGIN compliant
int value_allocate() {
    int v = 0;
    return v;
}
// END compliant
