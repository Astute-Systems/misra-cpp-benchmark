// MISRA C++:2023 Rule 10.1.1 (Advisory)
// The target type of a pointer or lvalue reference parameter should be const-qualified appropriately
//
// Example 1: Pointer parameter that is only read

// BEGIN violation
int read_through_pointer(int* p) {
    return *p;
}
// END violation

// BEGIN compliant
int read_through_const_pointer(const int* p) {
    return *p;
}
// END compliant
