// MISRA C++:2023 Rule 7.0.4 (Required)
// The operands of bitwise operators and shift operators shall be appropriate
//
// Example 2: Shift by an amount that is not smaller than the type width

// BEGIN violation
unsigned int shift_too_far(unsigned int x) {
    return x << 40;
}
// END violation

// BEGIN compliant
unsigned int shift_in_range(unsigned int x) {
    return x << 4;
}
// END compliant
