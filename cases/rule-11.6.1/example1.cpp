// MISRA C++:2023 Rule 11.6.1 (Advisory)
// All variables should be initialized
//
// Example 1: Local variable without an initializer

// BEGIN violation
int uninitialised_local() {
    int x;
    x = 4;
    return x;
}
// END violation

// BEGIN compliant
int initialised_local() {
    int x = 4;
    return x;
}
// END compliant
