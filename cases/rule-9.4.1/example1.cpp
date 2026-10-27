// MISRA C++:2023 Rule 9.4.1 (Required)
// All if ... else if constructs shall be terminated with an else statement
//
// Example 1: else-if chain without a final else

// BEGIN violation
int chain_without_else(int x) {
    int r = 0;
    if (x == 1) {
        r = 10;
    } else if (x == 2) {
        r = 20;
    }
    return r;
}
// END violation

// BEGIN compliant
int chain_with_else(int x) {
    int r = 0;
    if (x == 1) {
        r = 10;
    } else if (x == 2) {
        r = 20;
    } else {
        r = 0;
    }
    return r;
}
// END compliant
