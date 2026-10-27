// MISRA C++:2023 Rule 19.2.2 (Required)
// The #include directive shall be followed by either a <filename> or "filename" sequence
//
// Example 1: #include followed by a macro name

// BEGIN violation
#define HEADER_NAME <cstdint>
#include HEADER_NAME
// END violation

// BEGIN compliant
#include <cstddef>
// END compliant
