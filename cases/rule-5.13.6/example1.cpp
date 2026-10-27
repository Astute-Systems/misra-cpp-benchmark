// MISRA C++:2023 Rule 5.13.6 (Required)
// An integer-literal of type long long shall not use a single L or l in any suffix
//
// Example 1: Literal that has type long long but uses a single L (needs a 32-bit long; e.g. Windows or a 32-bit target)

// NOTE: platform dependent. On LP64 targets (Linux/macOS 64-bit) this
// literal has type long, so the rule is only violated where long is 32 bits.
// BEGIN violation
long long single_l_suffix() {
    return 4294967296L;
}
// END violation

// BEGIN compliant
long long ll_suffix() {
    return 4294967296LL;
}
// END compliant
