// MISRA C++:2023 Rule 0.0.2 (Advisory)
// Controlling expressions should not be invariant
//
// Example 2: Literal constant condition

// BEGIN violation
int constant_condition(int x) {
    if (2 > 1) {
        x += 1;
    }
    return x;
}
// END violation

// BEGIN compliant
int variable_condition(int x, int limit) {
    if (limit > 1) {
        x += 1;
    }
    return x;
}
// END compliant
