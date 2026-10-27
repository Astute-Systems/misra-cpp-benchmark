// MISRA C++:2023 Rule 5.13.1 (Required)
// Within character literals and non raw-string literals, backslash shall only form a defined escape sequence or universal character name
//
// Example 2: Undefined escape sequence in a character literal

// BEGIN violation
char bad_char_escape() {
    return '\y';
}
// END violation

// BEGIN compliant
char good_char_escape() {
    return '\n';
}
// END compliant
