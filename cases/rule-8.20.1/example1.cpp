// MISRA C++:2023 Rule 8.20.1 (Advisory)
// An unsigned arithmetic operation with constant operands should not wrap
//
// Example 1: Constant unsigned subtraction that wraps

// BEGIN violation
unsigned int wraps_below_zero() {
    return 0U - 1U;
}
// END violation

// BEGIN compliant
unsigned int does_not_wrap() {
    return 5U - 1U;
}
// END compliant
