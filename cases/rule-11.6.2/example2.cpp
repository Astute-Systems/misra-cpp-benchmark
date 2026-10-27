// MISRA C++:2023 Rule 11.6.2 (Mandatory)
// The value of an object must not be read before it has been set
//
// Example 2: Variable initialised on one branch only

// BEGIN violation
int conditional_init(bool c) {
    int r;
    if (c) {
        r = 1;
    }
    return r;
}
// END violation

// BEGIN compliant
int unconditional_init(bool c) {
    int r = 0;
    if (c) {
        r = 1;
    }
    return r;
}
// END compliant
