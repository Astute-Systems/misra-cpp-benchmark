// MISRA C++:2023 Rule 8.3.1 (Advisory)
// The built-in unary - operator should not be applied to an expression of unsigned type
//
// Example 2: Unary minus on an unsigned literal

// BEGIN violation
unsigned int negative_literal() {
    return -2U;
}
// END violation

// BEGIN compliant
int negative_signed_literal() {
    return -2;
}
// END compliant
