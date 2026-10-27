// MISRA C++:2023 Rule 0.2.1 (Advisory)
// Variables with limited visibility should be used at least once
//
// Example 1: Local variable that is never used

// BEGIN violation
int unused_local(int a) {
    int scratch = a * 2;
    return a;
}
// END violation

// BEGIN compliant
int used_local(int a) {
    int doubled = a * 2;
    return doubled;
}
// END compliant
