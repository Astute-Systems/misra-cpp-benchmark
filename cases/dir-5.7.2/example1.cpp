// MISRA C++:2023 Directive 5.7.2 (Advisory)
// Sections of code should not be "commented out"
//
// Example 1: Statements disabled with line comments

// BEGIN violation
int line_commented_code(int x) {
    // int y = x * 2;
    // if (y > 10) { return y; }
    return x;
}
// END violation

// BEGIN compliant
int described_in_prose(int x) {
    // The value is returned unchanged because no scaling is needed.
    return x;
}
// END compliant
