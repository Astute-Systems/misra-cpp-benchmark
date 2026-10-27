// MISRA C++:2023 Rule 9.4.2 (Required)
// The structure of a switch statement shall be appropriate
//
// Example 2: Implicit fall-through between non-empty cases

// BEGIN violation
int switch_fall_through(int m) {
    int r = 0;
    switch (m) {
        case 1:
            r += 1;
        case 2:
            r += 2;
            break;
        default:
            break;
    }
    return r;
}
// END violation

// BEGIN compliant
int switch_no_fall_through(int m) {
    int r = 0;
    switch (m) {
        case 1:
            r += 1;
            break;
        case 2:
            r += 2;
            break;
        default:
            break;
    }
    return r;
}
// END compliant
