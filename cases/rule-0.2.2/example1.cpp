// MISRA C++:2023 Rule 0.2.2 (Required)
// A named function parameter shall be used at least once
//
// Example 1: Named function parameter that is never used

// BEGIN violation
int ignores_second(int a, int b) {
    return a;
}
// END violation

// BEGIN compliant
int unnamed_second(int a, int) {
    return a;
}
// END compliant
