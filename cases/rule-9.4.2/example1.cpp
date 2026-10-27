// MISRA C++:2023 Rule 9.4.2 (Required)
// The structure of a switch statement shall be appropriate
//
// Example 1: switch without a default label

// BEGIN violation
int switch_without_default(int m) {
    switch (m) {
        case 1:
            return 1;
        case 2:
            return 2;
    }
    return 0;
}
// END violation

// BEGIN compliant
int switch_with_default(int m) {
    switch (m) {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return 0;
    }
}
// END compliant
