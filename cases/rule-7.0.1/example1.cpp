// MISRA C++:2023 Rule 7.0.1 (Required)
// There shall be no conversion from type bool
//
// Example 1: bool converted to int

// BEGIN violation
int bool_to_int(bool flag) {
    int i = flag;
    return i;
}
// END violation

// BEGIN compliant
int bool_to_int_explicit(bool flag) {
    int i = flag ? 1 : 0;
    return i;
}
// END compliant
