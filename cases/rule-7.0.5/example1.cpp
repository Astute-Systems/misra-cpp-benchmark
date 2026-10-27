// MISRA C++:2023 Rule 7.0.5 (Required)
// Integral promotion and the usual arithmetic conversions shall not change the signedness or the type category of an operand
//
// Example 1: Comparison of signed and unsigned operands

// BEGIN violation
bool mixed_sign_compare(int s, unsigned int u) {
    return s < u;
}
// END violation

// BEGIN compliant
bool same_sign_compare(unsigned int a, unsigned int b) {
    return a < b;
}
// END compliant
