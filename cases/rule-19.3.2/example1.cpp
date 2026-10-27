// MISRA C++:2023 Rule 19.3.2 (Required)
// A macro parameter immediately following a # operator shall not be immediately followed by a ## operator
//
// Example 1: # parameter immediately followed by ##

// BEGIN violation
#define BAD_STRING_PASTE(x) #x ## _suffix
// END violation

// BEGIN compliant
#define GOOD_STRINGIZE(x) #x
// END compliant
