// MISRA C++:2023 Rule 8.3.2 (Advisory)
// The built-in unary + operator should not be used
//
// Example 2: Unary plus used to decay a lambda

// BEGIN violation
int (*lambda_to_pointer())(int) {
    return +[](int v) { return v; };
}
// END violation

// BEGIN compliant
int identity_function(int v) {
    return v;
}

int (*function_pointer())(int) {
    return &identity_function;
}
// END compliant
