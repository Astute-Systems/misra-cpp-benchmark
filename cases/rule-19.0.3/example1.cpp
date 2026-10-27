// MISRA C++:2023 Rule 19.0.3 (Advisory)
// #include directives should only be preceded by preprocessor directives or comments
//
// Example 1: #include placed after a declaration

// BEGIN violation
int before_include = 0;
#include <cstdint>
// END violation
