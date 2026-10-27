// MISRA C++:2023 Rule 0.1.1 (Advisory)
// A write to a local object should be necessary
//
// Example 1: Value assigned and overwritten before being read

// BEGIN violation
int overwritten_value() {
    int x = 0;
    x = 5;
    return x;
}
// END violation

// BEGIN compliant
int single_write() {
    int x = 5;
    return x;
}
// END compliant
