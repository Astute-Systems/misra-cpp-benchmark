// MISRA C++:2023 Rule 8.20.1 (Advisory)
// An unsigned arithmetic operation with constant operands should not wrap
//
// Example 2: Constant unsigned addition that wraps

// BEGIN violation
unsigned int wraps_above_max() {
    return 0xFFFFFFFFU + 1U;
}
// END violation

// BEGIN compliant
unsigned int stays_in_range() {
    return 0xFFFFFFFEU + 1U;
}
// END compliant
