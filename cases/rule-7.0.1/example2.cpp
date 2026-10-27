// MISRA C++:2023 Rule 7.0.1 (Required)
// There shall be no conversion from type bool
//
// Example 2: bool used in arithmetic

// BEGIN violation
int bool_in_arithmetic(bool a, bool b) {
    return a + b;
}
// END violation

// BEGIN compliant
int bool_counted(bool a, bool b) {
    int total = 0;
    if (a) {
        ++total;
    }
    if (b) {
        ++total;
    }
    return total;
}
// END compliant
