// MISRA C++:2023 Rule 0.1.2 (Required)
// The value returned by a function shall be used
//
// Example 1: Return value of a user function discarded

int parse_digit(char c);

// BEGIN violation
void discards_result() {
    parse_digit('7');
}
// END violation

// BEGIN compliant
int uses_result() {
    return parse_digit('7');
}

void explicit_discard() {
    static_cast<void>(parse_digit('7'));
}
// END compliant
