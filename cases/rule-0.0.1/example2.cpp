// MISRA C++:2023 Rule 0.0.1 (Required)
// A function shall not contain unreachable statements
//
// Example 2: Statement placed after an endless loop

// BEGIN violation
int after_endless_loop(int x) {
    for (;;) {
        ++x;
    }
    return x;
}
// END violation

// BEGIN compliant
int loop_with_exit(int x) {
    for (;;) {
        ++x;
        if (x > 100) {
            break;
        }
    }
    return x;
}
// END compliant
