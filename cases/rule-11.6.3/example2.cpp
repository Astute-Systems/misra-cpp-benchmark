// MISRA C++:2023 Rule 11.6.3 (Required)
// Within an enumerator list, the value of an implicitly-specified enumeration constant shall be unique
//
// Example 2: Implicit enumerator repeats the previous value

// BEGIN violation
enum class Step : int { First = 5, Second = 10, Third, Fourth = 11 };
// END violation

// BEGIN compliant
enum class DistinctStep : int { First = 5, Second = 10, Third, Fourth = 12 };
// END compliant
