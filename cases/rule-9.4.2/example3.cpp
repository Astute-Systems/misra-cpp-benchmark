// MISRA C++:2023 Rule 9.4.2 (Required)
// The structure of a switch statement shall be appropriate
//
// Example 3: switch on a boolean condition

// BEGIN violation
int switch_on_bool(bool flag) {
    switch (flag) {
        case true:
            return 1;
        default:
            return 0;
    }
}
// END violation

// BEGIN compliant
int if_on_bool(bool flag) {
    if (flag) {
        return 1;
    }
    return 0;
}
// END compliant
