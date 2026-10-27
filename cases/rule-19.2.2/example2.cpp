// MISRA C++:2023 Rule 19.2.2 (Required)
// The #include directive shall be followed by either a <filename> or "filename" sequence
//
// Example 2: #include followed by a macro that expands to a <filename> sequence (compliant counterpart)

#define HEADER_NAME <cstdint>

// BEGIN compliant
#include HEADER_NAME
// END compliant
