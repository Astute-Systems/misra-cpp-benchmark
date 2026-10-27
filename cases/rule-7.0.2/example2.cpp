// MISRA C++:2023 Rule 7.0.2 (Required)
// There shall be no conversion to type bool
//
// Example 2: Pointer used as a condition

// BEGIN violation
int pointer_condition(const int* p) {
    if (p) {
        return *p;
    }
    return 0;
}
// END violation

// BEGIN compliant
int pointer_comparison(const int* p) {
    if (p != nullptr) {
        return *p;
    }
    return 0;
}
// END compliant
