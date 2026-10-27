// MISRA C++:2023 Rule 8.2.2 (Required)
// C-style casts and functional notation casts shall not be used
//
// Example 2: Functional notation cast

// BEGIN violation
double functional_cast(int i) {
    return double(i);
}
// END violation

// BEGIN compliant
double static_cast_to_double(int i) {
    return static_cast<double>(i);
}
// END compliant
