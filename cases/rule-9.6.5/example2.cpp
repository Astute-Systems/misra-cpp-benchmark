// MISRA C++:2023 Rule 9.6.5 (Required)
// A function with non-void return type shall return a value on all paths
//
// Example 2: switch where one case does not return

// BEGIN violation
int switch_missing_return(int m) {
    switch (m) {
        case 1:
            return 1;
        default:
            break;
    }
}
// END violation

// BEGIN compliant
int switch_returns_everywhere(int m) {
    switch (m) {
        case 1:
            return 1;
        default:
            return 0;
    }
}
// END compliant
