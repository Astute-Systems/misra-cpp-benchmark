// MISRA C++:2023 Rule 0.0.2 (Advisory)
// Controlling expressions should not be invariant
//
// Example 1: Comparison that is always true for an unsigned operand

// BEGIN violation
int always_true(unsigned int u) {
    if (u >= 0U) {
        return 1;
    }
    return 0;
}
// END violation

// BEGIN compliant
int depends_on_input(unsigned int u) {
    if (u >= 10U) {
        return 1;
    }
    return 0;
}
// END compliant
