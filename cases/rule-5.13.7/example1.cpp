// MISRA C++:2023 Rule 5.13.7 (Required)
// String literals with different encoding prefixes shall not be concatenated
//
// Example 1: Narrow and wide string literals concatenated

// BEGIN violation
const wchar_t* mixed_wide() {
    return "abc" L"def";
}
// END violation

// BEGIN compliant
const wchar_t* same_wide() {
    return L"abc" L"def";
}
// END compliant
