// MISRA C++:2023 Rule 4.1.1 (Required)
// A program shall conform to ISO/IEC 14882:2017 (C++17)
//
// Example 1: Variable length array (compiler extension)

// BEGIN violation
int vla_sum(int n) {
    int values[n];
    for (int i = 0; i < n; ++i) {
        values[i] = i;
    }
    return values[0];
}
// END violation

// BEGIN compliant
int fixed_sum() {
    int values[4] = {0, 1, 2, 3};
    return values[0];
}
// END compliant
