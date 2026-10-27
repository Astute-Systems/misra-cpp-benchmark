// MISRA C++:2023 Rule 11.3.2 (Advisory)
// The declaration of an object should contain no more than two levels of pointer indirection
//
// Example 2: Three levels of pointer indirection in a global declaration

// BEGIN violation
int*** g_triple = nullptr;
// END violation

// BEGIN compliant
int** g_double = nullptr;
// END compliant
