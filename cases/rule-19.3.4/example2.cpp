// MISRA C++:2023 Rule 19.3.4 (Required)
// Parentheses shall be used to ensure macro arguments are expanded appropriately
//
// Example 2: Only one use of the parameter is parenthesised

// BEGIN violation
#define CLAMP_LOW(v, lo) ((v) < lo ? lo : (v))

int clamped_low(int v) {
    return CLAMP_LOW(v, 1 + 1);
}
// END violation

// BEGIN compliant
#define CLAMP_LOW_SAFE(v, lo) ((v) < (lo) ? (lo) : (v))

int clamped_low_safely(int v) {
    return CLAMP_LOW_SAFE(v, 1 + 1);
}
// END compliant
