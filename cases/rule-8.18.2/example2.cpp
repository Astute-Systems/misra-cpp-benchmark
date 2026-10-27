// MISRA C++:2023 Rule 8.18.2 (Advisory)
// The result of an assignment operator should not be used
//
// Example 2: Chained assignment

// BEGIN violation
int chained_assignment() {
    int a = 0;
    int b = 0;
    a = b = 3;
    return a + b;
}
// END violation

// BEGIN compliant
int separate_assignments() {
    int a = 0;
    int b = 3;
    a = 3;
    return a + b;
}
// END compliant
