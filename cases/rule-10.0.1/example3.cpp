// MISRA C++:2023 Rule 10.0.1 (Advisory)
// A declaration should not declare more than one variable or member variable
//
// Example 3: Pointer and non-pointer declared together

// BEGIN violation
int pointer_and_value() {
    int v = 0;
    int *p = &v, q = 1;
    return *p + q;
}
// END violation

// BEGIN compliant
int pointer_and_value_split() {
    int v = 0;
    int* p = &v;
    int q = 1;
    return *p + q;
}
// END compliant
