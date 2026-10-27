// MISRA C++:2023 Rule 6.0.1 (Required)
// Block scope declarations shall not be visually ambiguous
//
// Example 1: Function declared inside a block

// BEGIN violation
int block_scope_function() {
    int compute(int);
    return 0;
}
// END violation

// BEGIN compliant
int compute_outside(int);

int no_block_scope_function() {
    return compute_outside(1);
}
// END compliant
