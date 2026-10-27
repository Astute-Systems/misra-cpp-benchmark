// MISRA C++:2023 Rule 9.6.1 (Advisory)
// The goto statement should not be used
//
// Example 2: Backward goto

// BEGIN violation
int backward_goto(int x) {
again:
    x += 1;
    if (x < 10) {
        goto again;
    }
    return x;
}
// END violation

// BEGIN compliant
int loop_instead_of_goto(int x) {
    do {
        x += 1;
    } while (x < 10);
    return x;
}
// END compliant
