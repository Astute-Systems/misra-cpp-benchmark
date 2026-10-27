// MISRA C++:2023 Rule 19.0.4 (Advisory)
// #undef should only be used for macros defined previously in the same file
//
// Example 1: #undef of a macro defined in a standard header

#include <climits>

// BEGIN violation
#undef INT_MAX
// END violation

// BEGIN compliant
#define LOCAL_LIMIT 4
#undef LOCAL_LIMIT
// END compliant
