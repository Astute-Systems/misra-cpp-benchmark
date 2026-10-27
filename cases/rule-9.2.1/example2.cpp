// MISRA C++:2023 Rule 9.2.1 (Required)
// An explicit type conversion shall not be an expression statement
//
// Example 2: Arithmetic result cast and discarded

// BEGIN violation
void cast_sum_statement(int a, int b) {
    static_cast<long>(a + b);
}
// END violation

// BEGIN compliant
long cast_sum_returned(int a, int b) {
    return static_cast<long>(a) + b;
}
// END compliant
