// MISRA C++:2023 Rule 15.0.1 (Required)
// Special member functions shall be provided appropriately
//
// Example 2: Copy constructor declared without copy assignment

// BEGIN violation
struct CopyOnly {
    CopyOnly() = default;
    CopyOnly(const CopyOnly& other) : v(other.v) {}
    int v = 0;
};
// END violation

// BEGIN compliant
struct RuleOfZero {
    int v = 0;
};
// END compliant
