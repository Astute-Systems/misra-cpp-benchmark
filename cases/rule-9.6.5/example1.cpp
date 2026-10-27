// MISRA C++:2023 Rule 9.6.5 (Required)
// A function with non-void return type shall return a value on all paths
//
// Example 1: Missing return on one path

// BEGIN violation
int missing_return(int x) {
    if (x > 0) {
        return 1;
    }
}
// END violation

// BEGIN compliant
int all_paths_return(int x) {
    if (x > 0) {
        return 1;
    }
    return 0;
}
// END compliant
