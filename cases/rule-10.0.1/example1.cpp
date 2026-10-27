// MISRA C++:2023 Rule 10.0.1 (Advisory)
// A declaration should not declare more than one variable or member variable
//
// Example 1: Several variables in one declaration

// BEGIN violation
int multiple_declarators() {
    int a = 1, b = 2;
    return a + b;
}
// END violation

// BEGIN compliant
int single_declarators() {
    int a = 1;
    int b = 2;
    return a + b;
}
// END compliant
