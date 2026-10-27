// MISRA C++:2023 Rule 5.13.5 (Required)
// The lowercase form of L shall not be used as the first character in a literal suffix
//
// Example 2: Lowercase l inside an unsigned suffix

// BEGIN violation
unsigned long lowercase_ul() {
    return 100ul;
}
// END violation

// BEGIN compliant
unsigned long uppercase_ul() {
    return 100UL;
}
// END compliant
