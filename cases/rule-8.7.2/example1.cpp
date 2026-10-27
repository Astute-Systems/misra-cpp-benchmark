// MISRA C++:2023 Rule 8.7.2 (Required)
// Subtraction between pointers shall only be applied to pointers that address elements of the same array
//
// Example 1: Subtraction of pointers into different arrays

// BEGIN violation
long subtract_different_arrays() {
    int a[4] = {};
    int b[4] = {};
    return &b[2] - &a[0];
}
// END violation

// BEGIN compliant
long subtract_same_array() {
    int a[4] = {};
    return &a[3] - &a[0];
}
// END compliant
