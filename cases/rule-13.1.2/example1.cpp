// MISRA C++:2023 Rule 13.1.2 (Required)
// A base class shall not be both virtual and non-virtual in the same hierarchy
//
// Example 1: Base class inherited both virtually and non-virtually

// BEGIN violation
struct Shared {};
struct Left : virtual Shared {};
struct Right : Shared {};
struct Diamond : Left, Right {};
// END violation

// BEGIN compliant
struct Single {};
struct OnlyChild : Single {};
// END compliant
