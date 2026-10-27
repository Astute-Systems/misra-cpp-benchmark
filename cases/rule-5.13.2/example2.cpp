// MISRA C++:2023 Rule 5.13.2 (Required)
// Octal escape sequences, hexadecimal escape sequences and universal character names shall be terminated
//
// Example 2: Hexadecimal escape followed by ordinary characters

// BEGIN violation
const char* hex_unterminated() {
    return "\x4g";
}
// END violation

// BEGIN compliant
const char* hex_terminated() {
    return "\x4" "g";
}
// END compliant
