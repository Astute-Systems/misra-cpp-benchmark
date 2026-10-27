// MISRA C++:2023 Rule 19.1.1 (Required)
// The defined preprocessor operator shall be used appropriately
//
// Example 1: defined produced by macro expansion

#define FEATURE 1

// BEGIN violation
#define HAS_FEATURE defined(FEATURE)

#if HAS_FEATURE
int feature_enabled();
#endif
// END violation

// BEGIN compliant
#if defined(FEATURE)
int feature_enabled_directly();
#endif
// END compliant
