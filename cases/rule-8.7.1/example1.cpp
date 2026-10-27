// MISRA C++:2023 Rule 8.7.1 (Required)
// Pointer arithmetic shall not form an invalid pointer
//
// Example 1: Pointer arithmetic beyond a single object

// BEGIN violation
int* past_scalar() {
    int x = 0;
    int* p = &x;
    return p + 5;
}
// END violation

// BEGIN compliant
int* within_array() {
    static int values[8] = {};
    int* p = values;
    return p + 5;
}
// END compliant
