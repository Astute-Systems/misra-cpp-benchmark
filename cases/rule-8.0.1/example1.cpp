// MISRA C++:2023 Rule 8.0.1 (Advisory)
// Parentheses should be used to make the meaning of an expression appropriately explicit
//
// Example 1: Mixed logical operators without parentheses

// BEGIN violation
bool mixed_logic(bool a, bool b, bool c) {
    return a && b || c;
}
// END violation

// BEGIN compliant
bool parenthesised_logic(bool a, bool b, bool c) {
    return (a && b) || c;
}
// END compliant
