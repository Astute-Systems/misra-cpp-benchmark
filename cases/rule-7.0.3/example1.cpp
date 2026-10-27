// MISRA C++:2023 Rule 7.0.3 (Required)
// The numerical value of a character shall not be used
//
// Example 1: Arithmetic on a character value

// BEGIN violation
char next_letter(char c) {
    return static_cast<char>(c + 1);
}
// END violation

// BEGIN compliant
bool is_letter_a(char c) {
    return c == 'a';
}
// END compliant
