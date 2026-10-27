// MISRA C++:2023 Rule 5.10.1 (Required)
// User-defined identifiers shall have an appropriate form
//
// Example 2: User-defined literal suffix without a leading underscore

// BEGIN violation
constexpr unsigned long long operator"" km(unsigned long long v) {
    return v * 1000ULL;
}
// END violation

// BEGIN compliant
constexpr unsigned long long operator"" _km(unsigned long long v) {
    return v * 1000ULL;
}
// END compliant
