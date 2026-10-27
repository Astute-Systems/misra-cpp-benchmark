// MISRA C++:2023 Rule 15.1.3 (Required)
// Conversion operators and constructors that are callable with a single argument shall be explicit
//
// Example 1: Converting constructor that is not explicit

// BEGIN violation
struct Meters {
    Meters(int value);
};
// END violation

// BEGIN compliant
struct ExplicitMeters {
    explicit ExplicitMeters(int value);
};
// END compliant
