// MISRA C++:2023 Rule 9.2.1 (Required)
// An explicit type conversion shall not be an expression statement
//
// Example 1: Cast used as an expression statement

// BEGIN violation
void cast_statement(double d) {
    static_cast<int>(d);
}
// END violation

// BEGIN compliant
int cast_assigned(double d) {
    int i = static_cast<int>(d);
    return i;
}
// END compliant
