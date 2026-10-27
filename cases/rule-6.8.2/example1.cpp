// MISRA C++:2023 Rule 6.8.2 (Mandatory)
// A function must not return a reference or a pointer to a local variable with automatic storage duration
//
// Example 1: Reference returned to a local variable

// BEGIN violation
int& reference_to_local() {
    int local = 1;
    return local;
}
// END violation

// BEGIN compliant
int value_of_local() {
    int local = 1;
    return local;
}
// END compliant
