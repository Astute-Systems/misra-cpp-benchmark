// MISRA C++:2023 Rule 5.13.4 (Required)
// Unsigned integer literals shall be appropriately suffixed
//
// Example 1: Hexadecimal literal of unsigned type without a suffix

// BEGIN violation
unsigned int high_bit() {
    return 0x80000000;
}
// END violation

// BEGIN compliant
unsigned int high_bit_suffixed() {
    return 0x80000000U;
}
// END compliant
