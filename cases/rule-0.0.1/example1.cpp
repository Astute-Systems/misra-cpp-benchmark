// MISRA C++:2023 Rule 0.0.1 (Required)
// A function shall not contain unreachable statements
//
// Example 1: Statements placed after an unconditional return

// BEGIN violation
int after_return(int x) {
    return x + 1;
    x = 0;
}
// END violation

// BEGIN compliant
int clamp_low(int x) {
    if (x < 0) {
        return 0;
    }
    return x;
}
// END compliant
