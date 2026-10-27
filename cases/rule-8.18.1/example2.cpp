// MISRA C++:2023 Rule 8.18.1 (Mandatory)
// An object or subobject must not be copied to an overlapping object
//
// Example 2: Overlapping std::copy

#include <algorithm>

// BEGIN violation
void overlapping_copy() {
    int a[8] = {};
    std::copy(a, a + 4, a + 1);
}
// END violation

// BEGIN compliant
void disjoint_copy() {
    int a[8] = {};
    std::copy(a, a + 4, a + 4);
}
// END compliant
