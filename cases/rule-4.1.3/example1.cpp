// MISRA C++:2023 Rule 4.1.3 (Required)
// There shall be no occurrence of undefined or critical unspecified behaviour
//
// Example 1: Division by a literal zero

// BEGIN violation
int divide_by_zero(int a) {
    return a / 0;
}
// END violation

// BEGIN compliant
int divide_checked(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}
// END compliant
