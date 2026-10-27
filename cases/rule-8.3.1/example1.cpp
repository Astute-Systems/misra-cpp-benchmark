// MISRA C++:2023 Rule 8.3.1 (Advisory)
// The built-in unary - operator should not be applied to an expression of unsigned type
//
// Example 1: Unary minus on an unsigned variable

// BEGIN violation
unsigned int negate_unsigned(unsigned int u) {
    return -u;
}
// END violation

// BEGIN compliant
int negate_signed(int s) {
    return -s;
}
// END compliant
