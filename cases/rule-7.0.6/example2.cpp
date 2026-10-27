// MISRA C++:2023 Rule 7.0.6 (Required)
// Converting transfers between numeric types shall be appropriate
//
// Example 2: Floating-point value assigned to an integer

// BEGIN violation
int truncate_double(double d) {
    int n = d;
    return n;
}
// END violation

// BEGIN compliant
double widen_float(float f) {
    double d = f;
    return d;
}
// END compliant
