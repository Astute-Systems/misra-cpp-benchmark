// MISRA C++:2023 Rule 13.3.3 (Required)
// The parameters in all declarations or overrides of a function shall either be unnamed or have identical names
//
// Example 2: Redeclaration uses a different parameter name

// BEGIN violation
void configure(int level);

void configure(int mode) {
    static_cast<void>(mode);
}
// END violation

// BEGIN compliant
void tune(int level);

void tune(int level) {
    static_cast<void>(level);
}
// END compliant
