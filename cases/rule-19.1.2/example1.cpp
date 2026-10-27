// MISRA C++:2023 Rule 19.1.2 (Required)
// All #else, #elif and #endif preprocessor directives shall reside in the same file as the #if, #ifdef or #ifndef directive to which they are related
//
// Example 1: #endif that closes a conditional opened in another file

// NO-COMPILE: the #endif in the included file has no matching #if in that
// file, which every compiler rejects. The example is therefore left out of
// compile_commands.json and exists only for tools that analyse it textually.
// BEGIN violation
#ifdef FEATURE_FLAG
#include "example1_tail.h"
// END violation
