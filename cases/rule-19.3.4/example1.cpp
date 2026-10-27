// MISRA C++:2023 Rule 19.3.4 (Required)
// Parentheses shall be used to ensure macro arguments are expanded appropriately
//
// Example 1: Macro parameter not parenthesised

// BEGIN violation
#define DOUBLE(x) x * 2

int doubled() {
    return DOUBLE(1 + 2);
}
// END violation

// BEGIN compliant
#define SAFE_DOUBLE(x) ((x) * 2)

int doubled_safely() {
    return SAFE_DOUBLE(1 + 2);
}
// END compliant
