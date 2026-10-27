// MISRA C++:2023 Rule 5.13.4 (Required)
// Unsigned integer literals shall be appropriately suffixed
//
// Example 2: 64-bit unsigned hexadecimal literal without a suffix

// BEGIN violation
unsigned long long all_ones() {
    return 0xFFFFFFFFFFFFFFFF;
}
// END violation

// BEGIN compliant
unsigned long long all_ones_suffixed() {
    return 0xFFFFFFFFFFFFFFFFULL;
}
// END compliant
