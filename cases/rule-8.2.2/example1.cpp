// MISRA C++:2023 Rule 8.2.2 (Required)
// C-style casts and functional notation casts shall not be used
//
// Example 1: C-style cast

// BEGIN violation
int c_style(double d) {
    return (int)d;
}
// END violation

// BEGIN compliant
int named_cast(double d) {
    return static_cast<int>(d);
}
// END compliant
