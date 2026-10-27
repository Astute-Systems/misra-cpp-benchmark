// MISRA C++:2023 Rule 9.6.1 (Advisory)
// The goto statement should not be used
//
// Example 1: Forward goto

// BEGIN violation
int forward_goto(int x) {
    if (x < 0) {
        goto done;
    }
    x += 1;
done:
    return x;
}
// END violation

// BEGIN compliant
int no_goto(int x) {
    if (x >= 0) {
        x += 1;
    }
    return x;
}
// END compliant
