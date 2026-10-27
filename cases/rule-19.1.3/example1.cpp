// MISRA C++:2023 Rule 19.1.3 (Required)
// All identifiers used in the controlling expression of #if or #elif preprocessing directives shall be defined prior to evaluation
//
// Example 1: Undefined identifier in an #if condition

// BEGIN violation
#if UNDEFINED_LEVEL > 1
int high_level();
#endif
// END violation

// BEGIN compliant
#define DEFINED_LEVEL 2

#if DEFINED_LEVEL > 1
int defined_high_level();
#endif
// END compliant
