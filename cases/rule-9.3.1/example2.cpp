// MISRA C++:2023 Rule 9.3.1 (Required)
// The body of an iteration-statement or a selection-statement shall be a compound-statement
//
// Example 2: Loops and else without braces

// BEGIN violation
int loops_without_braces(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += i;
    while (n > 0)
        --n;
    if (sum > 10) {
        sum = 10;
    } else
        sum = 0;
    return sum;
}
// END violation

// BEGIN compliant
int loops_with_braces(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += i;
    }
    while (n > 0) {
        --n;
    }
    if (sum > 10) {
        sum = 10;
    } else {
        sum = 0;
    }
    return sum;
}
// END compliant
