// MISRA C++:2023 Rule 9.5.1 (Advisory)
// Legacy for statements should be simple
//
// Example 3: Loop without condition and increment

// BEGIN violation
int open_ended_for(int n) {
    int i = 0;
    for (;;) {
        if (i >= n) {
            break;
        }
        ++i;
    }
    return i;
}
// END violation

// BEGIN compliant
int simple_for(int n) {
    int total = 0;
    for (int i = n; i > 0; --i) {
        total += i;
    }
    return total;
}
// END compliant
