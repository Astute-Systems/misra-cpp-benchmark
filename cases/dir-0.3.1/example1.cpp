// MISRA C++:2023 Directive 0.3.1 (Advisory)
// Floating-point arithmetic should be used appropriately
//
// Example 1: Equality comparison of floating-point values

// BEGIN violation
bool same_value(double a, double b) {
    return a == b;
}
// END violation

// BEGIN compliant
bool close_enough(double a, double b, double eps) {
    double diff = a - b;
    return (diff < eps) && (diff > -eps);
}
// END compliant
