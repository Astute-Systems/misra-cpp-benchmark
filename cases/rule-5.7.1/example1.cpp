// MISRA C++:2023 Rule 5.7.1 (Required)
// The character sequence /* shall not be used within a C-style comment
//
// Example 1: Comment start marker inside a C-style comment

// BEGIN violation
/* outer comment /* accidental inner start */
int nested_marker() {
    return 1;
}
// END violation

// BEGIN compliant
/* a plain comment */
int plain_comment() {
    return 1;
}
// END compliant
