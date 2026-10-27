// MISRA C++:2023 Rule 9.4.1 (Required)
// All if ... else if constructs shall be terminated with an else statement
//
// Example 2: Longer else-if chain without a final else

// BEGIN violation
int long_chain_without_else(int x) {
    if (x < 0) {
        return -1;
    } else if (x == 0) {
        return 0;
    } else if (x < 10) {
        return 1;
    }
    return 2;
}
// END violation

// BEGIN compliant
int long_chain_with_else(int x) {
    if (x < 0) {
        return -1;
    } else if (x == 0) {
        return 0;
    } else if (x < 10) {
        return 1;
    } else {
        return 2;
    }
}
// END compliant
