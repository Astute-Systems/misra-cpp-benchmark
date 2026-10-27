// MISRA C++:2023 Rule 5.13.7 (Required)
// String literals with different encoding prefixes shall not be concatenated
//
// Example 2: Unprefixed literal concatenated with a prefixed one (compliant counterpart)

// BEGIN compliant
const wchar_t* unprefixed_and_wide() {
    return "abc" L"def";
}

const char16_t* unprefixed_and_utf16() {
    return "x" u"y";
}
// END compliant
