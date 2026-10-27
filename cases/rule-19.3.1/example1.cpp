// MISRA C++:2023 Rule 19.3.1 (Advisory)
// The # and ## preprocessor operators should not be used
//
// Example 1: Stringizing operator

// BEGIN violation
#define TO_STRING(x) #x

const char* stringized_name() {
    return TO_STRING(abc);
}
// END violation

// BEGIN compliant
const char* plain_name() {
    return "abc";
}
// END compliant
