// MISRA C++:2023 Rule 8.7.1 (Required)
// Pointer arithmetic shall not form an invalid pointer
//
// Example 2: Pointer arithmetic beyond the end of an array

// BEGIN violation
int* past_array_end() {
    int a[4] = {};
    return a + 6;
}
// END violation

// BEGIN compliant
int* one_past_array_end() {
    static int a[4] = {};
    return a + 4;
}
// END compliant
