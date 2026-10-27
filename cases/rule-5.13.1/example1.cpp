// MISRA C++:2023 Rule 5.13.1 (Required)
// Within character literals and non raw-string literals, backslash shall only form a defined escape sequence or universal character name
//
// Example 1: Undefined escape sequence in a string literal

// BEGIN violation
const char* bad_string_escape() {
    return "path\qname";
}
// END violation

// BEGIN compliant
const char* good_string_escape() {
    return "path\\qname";
}
// END compliant
