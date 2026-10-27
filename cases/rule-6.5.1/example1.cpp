// MISRA C++:2023 Rule 6.5.1 (Advisory)
// A function or object with external linkage should be introduced in a header file
//
// Example 1: Function with external linkage that no header declares

#include "example1.h"

// BEGIN violation
int not_in_any_header() {
    return 1;
}
// END violation

// BEGIN compliant
int declared_in_header() {
    return 2;
}
// END compliant
