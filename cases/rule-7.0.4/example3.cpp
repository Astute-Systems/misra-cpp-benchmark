// MISRA C++:2023 Rule 7.0.4 (Required)
// The operands of bitwise operators and shift operators shall be appropriate
//
// Example 3: Complement of a signed operand

// BEGIN violation
int complement_signed(int v) {
    return ~v;
}
// END violation

// BEGIN compliant
unsigned int complement_unsigned(unsigned int v) {
    return ~v;
}
// END compliant
