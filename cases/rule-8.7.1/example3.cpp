// MISRA C++:2023 Rule 8.7.1 (Required)
// Pointer arithmetic shall not form an invalid pointer
//
// Example 3: Offset applied directly to the address of a variable

// BEGIN violation
int* direct_past_scalar() {
    static int x = 0;
    return &x + 5;
}
// END violation

// BEGIN compliant
int* direct_one_past_scalar() {
    static int x = 0;
    return &x + 1;
}
// END compliant
