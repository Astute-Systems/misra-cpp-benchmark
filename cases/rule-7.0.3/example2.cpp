// MISRA C++:2023 Rule 7.0.3 (Required)
// The numerical value of a character shall not be used
//
// Example 2: Character converted to its numeric value

// BEGIN violation
int char_code(char c) {
    return static_cast<int>(c) * 2;
}
// END violation

// BEGIN compliant
int char_selector(char c) {
    switch (c) {
        case 'a':
            return 1;
        default:
            return 0;
    }
}
// END compliant
