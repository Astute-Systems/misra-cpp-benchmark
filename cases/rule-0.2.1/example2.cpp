// MISRA C++:2023 Rule 0.2.1 (Advisory)
// Variables with limited visibility should be used at least once
//
// Example 2: Variable with internal linkage that is never used

// BEGIN violation
static int unused_file_static = 3;
// END violation

// BEGIN compliant
static int used_file_static = 3;

int read_file_static() {
    return used_file_static;
}
// END compliant
