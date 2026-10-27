// MISRA C++:2023 Rule 21.6.1 (Advisory)
// Dynamic memory should not be used
//
// Example 1: Allocation with new

// BEGIN violation
int* allocate_with_new() {
    return new int(1);
}
// END violation

// BEGIN compliant
int automatic_storage() {
    int value = 1;
    return value;
}
// END compliant
