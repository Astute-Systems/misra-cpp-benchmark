// MISRA C++:2023 Rule 5.13.7 (Required)
// String literals with different encoding prefixes shall not be concatenated
//
// Example 2: Narrow and UTF-16 string literals concatenated

// BEGIN violation
const char16_t* mixed_utf16() {
    return "x" u"y";
}
// END violation

// BEGIN compliant
const char16_t* same_utf16() {
    return u"x" u"y";
}
// END compliant
