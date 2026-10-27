// MISRA C++:2023 Rule 7.11.1 (Required)
// nullptr shall be the only form of the null-pointer-constant
//
// Example 1: Literal zero and NULL as null pointer constants

#include <cstddef>

// BEGIN violation
int* zero_pointer() {
    int* p = 0;
    return p;
}

int* null_macro_pointer() {
    int* p = NULL;
    return p;
}
// END violation

// BEGIN compliant
int* nullptr_pointer() {
    int* p = nullptr;
    return p;
}
// END compliant
