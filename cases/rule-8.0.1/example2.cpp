// MISRA C++:2023 Rule 8.0.1 (Advisory)
// Parentheses should be used to make the meaning of an expression appropriately explicit
//
// Example 2: Mixed arithmetic and shift operators without parentheses

// BEGIN violation
int mixed_shift(int a, int b, int c) {
    return a + b << c;
}
// END violation

// BEGIN compliant
int parenthesised_shift(int a, int b, int c) {
    return (a + b) << c;
}
// END compliant
