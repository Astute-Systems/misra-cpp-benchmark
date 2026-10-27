// MISRA C++:2023 Rule 9.5.1 (Advisory)
// Legacy for statements should be simple
//
// Example 1: Loop counter modified inside the body

// BEGIN violation
int counter_modified(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            i += 1;
        }
        sum += i;
    }
    return sum;
}
// END violation

// BEGIN compliant
int counter_untouched(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += i;
    }
    return sum;
}
// END compliant
