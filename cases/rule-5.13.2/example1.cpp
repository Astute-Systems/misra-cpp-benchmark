// MISRA C++:2023 Rule 5.13.2 (Required)
// Octal escape sequences, hexadecimal escape sequences and universal character names shall be terminated
//
// Example 1: Octal escape followed by ordinary characters

// BEGIN violation
const char* octal_unterminated() {
    return "\101B";
}
// END violation

// BEGIN compliant
const char* octal_terminated() {
    return "\101" "B";
}
// END compliant
