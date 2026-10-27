// MISRA C++:2023 Rule 7.11.1 (Required)
// nullptr shall be the only form of the null-pointer-constant
//
// Example 2: Pointer compared with literal zero

// BEGIN violation
bool compare_with_zero(const int* p) {
    return p == 0;
}
// END violation

// BEGIN compliant
bool compare_with_nullptr(const int* p) {
    return p == nullptr;
}
// END compliant
