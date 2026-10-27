// MISRA C++:2023 Rule 6.4.1 (Required)
// A variable declared in an inner scope shall not hide a variable declared in an outer scope
//
// Example 2: Local variable hides a global variable

// BEGIN violation
int g_total = 0;

int hides_global() {
    int g_total = 1;
    return g_total;
}
// END violation

// BEGIN compliant
int g_sum = 0;

int does_not_hide_global() {
    int partial = 1;
    return partial + g_sum;
}
// END compliant
