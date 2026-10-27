// MISRA C++:2023 Rule 19.3.1 (Advisory)
// The # and ## preprocessor operators should not be used
//
// Example 2: Token-pasting operator

// BEGIN violation
#define JOIN(a, b) a##b

int pasted_identifier() {
    int ab = 1;
    return JOIN(a, b);
}
// END violation

// BEGIN compliant
int plain_identifier() {
    int ab = 1;
    return ab;
}
// END compliant
