// MISRA C++:2023 Rule 7.0.6 (Required)
// Converting transfers between numeric types shall be appropriate
//
// Example 1: Implicit narrowing between integer types

// BEGIN violation
short narrow_integer(int i) {
    short s = i;
    return s;
}
// END violation

// BEGIN compliant
long widen_integer(int i) {
    long l = i;
    return l;
}
// END compliant
