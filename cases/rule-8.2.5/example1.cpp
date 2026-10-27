// MISRA C++:2023 Rule 8.2.5 (Required)
// reinterpret_cast shall not be used
//
// Example 1: reinterpret_cast between pointer types

// BEGIN violation
int* reinterpret_float(float* f) {
    return reinterpret_cast<int*>(f);
}
// END violation

// BEGIN compliant
const float* add_const(float* f) {
    return static_cast<const float*>(f);
}
// END compliant
