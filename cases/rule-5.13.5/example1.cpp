// MISRA C++:2023 Rule 5.13.5 (Required)
// The lowercase form of L shall not be used as the first character in a literal suffix
//
// Example 1: Lowercase l suffix

// BEGIN violation
long lowercase_l() {
    return 10l;
}
// END violation

// BEGIN compliant
long uppercase_l() {
    return 10L;
}
// END compliant
