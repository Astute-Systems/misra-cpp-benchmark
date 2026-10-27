// MISRA C++:2023 Rule 8.14.1 (Advisory)
// The right-hand operand of a logical && or || operator should not contain persistent side effects
//
// Example 2: Increment through a pointer in the right operand of ||

// BEGIN violation
bool side_effect_or(bool ready, const int* p) {
    return ready || (*p++ == 1);
}
// END violation

// BEGIN compliant
bool no_side_effect_or(bool ready, const int* p) {
    return ready || (*p == 1);
}
// END compliant
