// MISRA C++:2023 Rule 11.6.3 (Required)
// Within an enumerator list, the value of an implicitly-specified enumeration constant shall be unique
//
// Example 1: Implicit enumerator duplicates an explicit value

// BEGIN violation
enum class Code : int { A = 1, B, C = 2 };
// END violation

// BEGIN compliant
enum class UniqueCode : int { A = 1, B, C = 3 };
// END compliant
