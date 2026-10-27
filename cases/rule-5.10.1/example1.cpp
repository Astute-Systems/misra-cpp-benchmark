// MISRA C++:2023 Rule 5.10.1 (Required)
// User-defined identifiers shall have an appropriate form
//
// Example 1: Identifiers reserved by the language

// BEGIN violation
int reserved_names() {
    int _Reserved = 1;
    int double__underscore = 2;
    return _Reserved + double__underscore;
}
// END violation

// BEGIN compliant
int ordinary_names() {
    int first_value = 1;
    int second_value = 2;
    return first_value + second_value;
}
// END compliant
