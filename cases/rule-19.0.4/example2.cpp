// MISRA C++:2023 Rule 19.0.4 (Advisory)
// #undef should only be used for macros defined previously in the same file
//
// Example 2: #undef of a macro that was never defined in this file

#include <cstdio>

// BEGIN violation
#undef EOF
// END violation

// BEGIN compliant
#define LOCAL_FLAG 1
#undef LOCAL_FLAG
// END compliant
