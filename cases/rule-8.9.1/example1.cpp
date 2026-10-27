// MISRA C++:2023 Rule 8.9.1 (Required)
// The built-in relational operators >, >=, < and <= shall not be applied to objects of pointer type, except where they point to elements of the same array
//
// Example 1: Relational comparison of pointers into different arrays

// BEGIN violation
bool compare_different_arrays() {
    int a[4] = {};
    int b[4] = {};
    return &a[0] < &b[0];
}
// END violation

// BEGIN compliant
bool compare_same_array() {
    int a[4] = {};
    return &a[0] < &a[3];
}
// END compliant
