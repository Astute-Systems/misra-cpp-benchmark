// MISRA C++:2023 Rule 5.7.3 (Required)
// Line-splicing shall not be used in // comments
//
// Example 1: Backslash at the end of a line comment

// BEGIN violation
// this comment continues on the next line \
   and the next line is swallowed by the comment
int spliced_comment() {
    return 1;
}
// END violation

// BEGIN compliant
// this comment ends on its own line
int unspliced_comment() {
    return 1;
}
// END compliant
