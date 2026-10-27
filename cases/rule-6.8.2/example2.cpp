// MISRA C++:2023 Rule 6.8.2 (Mandatory)
// A function must not return a reference or a pointer to a local variable with automatic storage duration
//
// Example 2: Pointer returned to a local array

// BEGIN violation
int* pointer_to_local() {
    int local[4] = {1, 2, 3, 4};
    return local;
}
// END violation

// BEGIN compliant
int first_of_local() {
    int local[4] = {1, 2, 3, 4};
    return local[0];
}
// END compliant
