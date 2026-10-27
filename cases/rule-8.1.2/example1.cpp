// MISRA C++:2023 Rule 8.1.2 (Advisory)
// Variables should be captured explicitly in a non-transient lambda
//
// Example 1: Stored lambda with a default capture

// BEGIN violation
int default_capture() {
    int a = 1;
    int b = 2;
    auto f = [=] { return a + b; };
    return f();
}
// END violation

// BEGIN compliant
int explicit_capture() {
    int a = 1;
    int b = 2;
    auto f = [a, b] { return a + b; };
    return f();
}
// END compliant
