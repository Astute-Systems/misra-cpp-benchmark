// MISRA C++:2023 Rule 10.2.2 (Advisory)
// Unscoped enumerations should not be declared
//
// Example 1: Unscoped enumeration with a fixed underlying type

// BEGIN violation
enum Level : int { Low, High };
// END violation

// BEGIN compliant
enum class Priority : int { Low, High };
// END compliant
