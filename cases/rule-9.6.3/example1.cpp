// MISRA C++:2023 Rule 9.6.3 (Required)
// The goto statement shall jump to a label declared later in the function body
//
// Example 1: Backward goto used as a loop

// BEGIN violation
int retry_goto(int attempts) {
retry:
    --attempts;
    if (attempts > 0) {
        goto retry;
    }
    return attempts;
}
// END violation

// BEGIN compliant
int retry_loop(int attempts) {
    while (attempts > 0) {
        --attempts;
    }
    return attempts;
}
// END compliant
