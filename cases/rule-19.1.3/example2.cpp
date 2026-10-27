// MISRA C++:2023 Rule 19.1.3 (Required)
// All identifiers used in the controlling expression of #if or #elif preprocessing directives shall be defined prior to evaluation
//
// Example 2: Undefined identifier in an #elif condition

#define MODE 1

// BEGIN violation
#if MODE == 0
int mode_zero();
#elif UNDEFINED_MODE == 1
int mode_one();
#endif
// END violation

// BEGIN compliant
#define OTHER_MODE 1

#if MODE == 0
int mode_zero_again();
#elif OTHER_MODE == 1
int mode_one_again();
#endif
// END compliant
