// MISRA C++:2023 Rule 8.19.1 (Advisory)
// The comma operator should not be used
//
// Example 1: Comma operator in a statement

// BEGIN violation
int comma_statement(int i, int j) {
    i++, j--;
    return i + j;
}
// END violation

// BEGIN compliant
int separate_statements(int i, int j) {
    i++;
    j--;
    return i + j;
}
// END compliant
