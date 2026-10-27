// MISRA C++:2023 Rule 10.2.1 (Required)
// An enumeration shall be defined with an explicit underlying type
//
// Example 2: Scoped enumeration without an underlying type

// BEGIN violation
enum class Mode { Idle, Busy };
// END violation

// BEGIN compliant
enum class Phase : unsigned char { Start, Stop };
// END compliant
