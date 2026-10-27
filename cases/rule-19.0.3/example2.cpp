// MISRA C++:2023 Rule 19.0.3 (Advisory)
// #include directives should only be preceded by preprocessor directives or comments
//
// Example 2: #include placed only after directives and comments (compliant counterpart)

// A comment may come first.
#define BEFORE_INCLUDE 1

// BEGIN compliant
#include <cstdint>
// END compliant
