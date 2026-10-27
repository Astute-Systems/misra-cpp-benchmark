// MISRA C++:2023 Rule 6.0.2 (Advisory)
// When an array with external linkage is declared, its size should be explicitly specified
//
// Example 1: Array with external linkage declared without a size

// BEGIN violation
extern int unsized_table[];
// END violation

// BEGIN compliant
extern int sized_table[4];
// END compliant
