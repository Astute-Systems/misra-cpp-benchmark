// MISRA C++:2023 Rule 6.0.1 (Required)
// Block scope declarations shall not be visually ambiguous
//
// Example 2: Most vexing parse

struct Widget {};

// BEGIN violation
void vexing() {
    Widget w();
}
// END violation

// BEGIN compliant
void not_vexing() {
    Widget w{};
    static_cast<void>(w);
}
// END compliant
