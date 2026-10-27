// MISRA C++:2023 Rule 5.0.1 (Advisory)
// Trigraph-like sequences should not be used
//
// Example 1: Trigraph-like sequence inside a string literal

// BEGIN violation
const char* surprised() {
    return "What??!";
}
// END violation

// BEGIN compliant
const char* surprised_safe() {
    return "What?" "?!";
}
// END compliant
