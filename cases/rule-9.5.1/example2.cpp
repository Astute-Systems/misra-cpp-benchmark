// MISRA C++:2023 Rule 9.5.1 (Advisory)
// Legacy for statements should be simple
//
// Example 2: Loop with two counters

// BEGIN violation
int two_counters(int n) {
    int sum = 0;
    for (int i = 0, j = n; i < j; ++i, --j) {
        sum += i;
    }
    return sum;
}
// END violation

// BEGIN compliant
int one_counter(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += i;
    }
    return sum;
}
// END compliant
