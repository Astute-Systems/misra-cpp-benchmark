// MISRA C++:2023 Rule 19.0.1 (Required)
// A line whose first token is # shall be a valid preprocessing directive
//
// Example 1: Unknown directive inside a skipped group

// BEGIN violation
#if 0
#frobnicate everything
#endif
// END violation

// BEGIN compliant
#if 0
#define SKIPPED_BUT_VALID 1
#endif
// END compliant
