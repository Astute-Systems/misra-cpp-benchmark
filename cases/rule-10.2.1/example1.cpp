// MISRA C++:2023 Rule 10.2.1 (Required)
// An enumeration shall be defined with an explicit underlying type
//
// Example 1: Unscoped enumeration without an underlying type

// BEGIN violation
enum Color { Red, Green, Blue };
// END violation

// BEGIN compliant
enum Shade : int { Light, Dark };
// END compliant
