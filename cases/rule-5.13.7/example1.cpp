// MISRA C++:2023 Rule 5.13.7 (Required)
// String literals with different encoding prefixes shall not be concatenated
//
// Example 1: Wide and UTF-16 string literals concatenated

// NO-COMPILE: GCC and Clang reject the concatenation of two different
// encoding prefixes, so this example is left out of compile_commands.json.
// BEGIN violation
const wchar_t* mixed_prefixes() {
    return L"abc" u"def";
}
// END violation

// BEGIN compliant
const wchar_t* same_prefix() {
    return L"abc" L"def";
}
// END compliant
