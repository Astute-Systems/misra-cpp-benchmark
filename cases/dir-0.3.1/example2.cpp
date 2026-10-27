// MISRA C++:2023 Directive 0.3.1 (Advisory)
// Floating-point arithmetic should be used appropriately
//
// Example 2: Floating-point loop counter terminated by inequality

// BEGIN violation
int float_loop() {
    int steps = 0;
    for (float f = 0.0F; f != 1.0F; f += 0.1F) {
        ++steps;
    }
    return steps;
}
// END violation

// BEGIN compliant
int integer_loop() {
    int steps = 0;
    for (int i = 0; i < 10; ++i) {
        ++steps;
    }
    return steps;
}
// END compliant
