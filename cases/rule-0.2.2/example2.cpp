// MISRA C++:2023 Rule 0.2.2 (Required)
// A named function parameter shall be used at least once
//
// Example 2: Unused lambda parameter

// BEGIN violation
int lambda_unused_parameter() {
    auto f = [](int used, int unused) { return used; };
    return f(1, 2);
}
// END violation

// BEGIN compliant
int lambda_unnamed_parameter() {
    auto f = [](int used, int) { return used; };
    return f(1, 2);
}
// END compliant
