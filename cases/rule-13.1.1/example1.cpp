// MISRA C++:2023 Rule 13.1.1 (Advisory)
// Classes should not be inherited virtually
//
// Example 1: Virtual inheritance

// BEGIN violation
struct Root {};
struct VirtualChild : virtual Root {};
// END violation

// BEGIN compliant
struct PlainRoot {};
struct PlainChild : PlainRoot {};
// END compliant
