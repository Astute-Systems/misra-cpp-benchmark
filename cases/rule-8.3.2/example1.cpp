// MISRA C++:2023 Rule 8.3.2 (Advisory)
// The built-in unary + operator should not be used
//
// Example 1: Unary plus on an integer

// BEGIN violation
int unary_plus(int a) {
    return +a;
}
// END violation

// BEGIN compliant
int no_unary_plus(int a) {
    return a;
}
// END compliant
