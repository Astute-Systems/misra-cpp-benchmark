// MISRA C++:2023 Rule 7.0.2 (Required)
// There shall be no conversion to type bool
//
// Example 2: Pointer stored in a bool without a comparison

// BEGIN violation
bool pointer_to_bool(const int* p) {
    bool has_value = p;
    return has_value;
}
// END violation

// BEGIN compliant
bool pointer_compared(const int* p) {
    bool has_value = (p != nullptr);
    return has_value;
}
// END compliant
