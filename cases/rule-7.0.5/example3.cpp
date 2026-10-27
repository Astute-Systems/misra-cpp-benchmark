// MISRA C++:2023 Rule 7.0.5 (Required)
// Integral promotion and the usual arithmetic conversions shall not change the signedness or the type category of an operand
//
// Example 3: Integer operand converted to floating point

// BEGIN violation
float int_times_float(int i, float f) {
    return i * f;
}
// END violation

// BEGIN compliant
float float_times_float(float a, float f) {
    return a * f;
}
// END compliant
