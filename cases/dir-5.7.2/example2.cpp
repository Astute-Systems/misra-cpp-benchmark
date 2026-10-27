// MISRA C++:2023 Directive 5.7.2 (Advisory)
// Sections of code should not be "commented out"
//
// Example 2: Loop disabled with a block comment

// BEGIN violation
int block_commented_code(int n) {
    int total = 0;
    /* for (int i = 0; i < n; ++i) {
           total += i;
       } */
    return total + n;
}
// END violation

// BEGIN compliant
int block_prose(int n) {
    int total = 0;
    /* The accumulation loop was removed because the closed form is used. */
    return total + n;
}
// END compliant
