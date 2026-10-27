// MISRA C++:2023 Rule 9.3.1 (Required)
// The body of an iteration-statement or a selection-statement shall be a compound-statement
//
// Example 1: if without braces

// BEGIN violation
int if_without_braces(int x) {
    if (x > 0)
        x++;
    return x;
}
// END violation

// BEGIN compliant
int if_with_braces(int x) {
    if (x > 0) {
        x++;
    }
    return x;
}
// END compliant
