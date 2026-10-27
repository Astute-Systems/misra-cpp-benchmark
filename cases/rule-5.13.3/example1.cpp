// MISRA C++:2023 Rule 5.13.3 (Required)
// Octal constants shall not be used
//
// Example 1: Octal integer literal

// BEGIN violation
int file_mode() {
    return 0755;
}
// END violation

// BEGIN compliant
int file_mode_decimal() {
    return 493;
}
// END compliant
