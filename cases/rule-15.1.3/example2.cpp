// MISRA C++:2023 Rule 15.1.3 (Required)
// Conversion operators and constructors that are callable with a single argument shall be explicit
//
// Example 2: Conversion operator that is not explicit

// BEGIN violation
struct Counter {
    operator int() const;
};
// END violation

// BEGIN compliant
struct ExplicitCounter {
    explicit operator int() const;
};
// END compliant
