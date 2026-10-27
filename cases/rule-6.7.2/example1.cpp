// MISRA C++:2023 Rule 6.7.2 (Required)
// Global variables shall not be used
//
// Example 1: Mutable global variable

// BEGIN violation
int g_counter = 0;
// END violation

// BEGIN compliant
constexpr int kLimit = 10;
// END compliant
