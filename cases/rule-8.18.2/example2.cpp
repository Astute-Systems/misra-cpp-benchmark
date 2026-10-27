// MISRA C++:2023 Rule 8.18.2 (Advisory)
// The result of an assignment operator should not be used
//
// Example 2: Value of an assignment used in an expression

// BEGIN violation
int assignment_in_expression(int a) {
    int b = (a = 3) + 1;
    return a + b;
}
// END violation

// BEGIN compliant
int assignment_as_statement(int a) {
    a = 3;
    int b = a + 1;
    return a + b;
}
// END compliant
