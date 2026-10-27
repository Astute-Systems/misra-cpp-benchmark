// MISRA C++:2023 Rule 5.0.1 (Advisory)
// Trigraph-like sequences should not be used
//
// Example 2: Another trigraph-like sequence

// BEGIN violation
const char* bracket_like() {
    return "??(index??)";
}
// END violation

// BEGIN compliant
const char* bracket_plain() {
    return "[index]";
}
// END compliant
