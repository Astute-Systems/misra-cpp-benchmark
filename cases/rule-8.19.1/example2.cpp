// MISRA C++:2023 Rule 8.19.1 (Advisory)
// The comma operator should not be used
//
// Example 2: Comma operator in an initializer

// BEGIN violation
int comma_value(int a, int b) {
    int x = (a, b);
    return x;
}
// END violation

// BEGIN compliant
int plain_value(int a, int b) {
    static_cast<void>(a);
    int x = b;
    return x;
}
// END compliant
