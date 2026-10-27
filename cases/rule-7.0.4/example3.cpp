// MISRA C++:2023 Rule 7.0.4 (Required)
// The operands of bitwise operators and shift operators shall be appropriate
//
// Example 3: Complement of a narrow unsigned operand

// BEGIN violation
unsigned char complement_narrow(unsigned char v) {
    return static_cast<unsigned char>(~v);
}
// END violation

// BEGIN compliant
unsigned int complement_wide(unsigned int v) {
    return ~v;
}
// END compliant
