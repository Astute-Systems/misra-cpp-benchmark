// MISRA C++:2023 Rule 7.0.2 (Required)
// There shall be no conversion to type bool
//
// Example 1: Integer used as a condition

// BEGIN violation
int integer_condition(int n) {
    if (n) {
        return 1;
    }
    return 0;
}
// END violation

// BEGIN compliant
int integer_comparison(int n) {
    if (n != 0) {
        return 1;
    }
    return 0;
}
// END compliant
