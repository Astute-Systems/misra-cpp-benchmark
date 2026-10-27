// MISRA C++:2023 Rule 11.3.2 (Advisory)
// The declaration of an object should contain no more than two levels of pointer indirection
//
// Example 1: Three levels of pointer indirection

// BEGIN violation
int triple_pointer(int*** p) {
    return ***p;
}
// END violation

// BEGIN compliant
int double_pointer(int** p) {
    return **p;
}
// END compliant
