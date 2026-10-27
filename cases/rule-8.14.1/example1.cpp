// MISRA C++:2023 Rule 8.14.1 (Advisory)
// The right-hand operand of a logical && or || operator should not contain persistent side effects
//
// Example 1: Increment in the right operand of &&

// BEGIN violation
bool side_effect_and(bool ok, int count) {
    return ok && (count++ > 3);
}
// END violation

// BEGIN compliant
bool no_side_effect_and(bool ok, int count) {
    return ok && (count > 3);
}
// END compliant
