// MISRA C++:2023 Directive 0.3.2 (Required)
// A function call shall not violate the function's preconditions
//
// Example 1: Dereference of a pointer that is known to be null

// BEGIN violation
int null_dereference() {
    int* p = nullptr;
    return *p;
}
// END violation

// BEGIN compliant
int checked_dereference(int* p) {
    if (p != nullptr) {
        return *p;
    }
    return 0;
}
// END compliant
