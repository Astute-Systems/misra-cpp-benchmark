// MISRA C++:2023 Rule 7.0.4 (Required)
// The operands of bitwise operators and shift operators shall be appropriate
//
// Example 1: Bitwise AND on a signed operand

// BEGIN violation
int mask_signed(int a) {
    return a & 0x0F;
}
// END violation

// BEGIN compliant
unsigned int mask_unsigned(unsigned int a) {
    return a & 0x0FU;
}
// END compliant
