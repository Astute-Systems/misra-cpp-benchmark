// MISRA C++:2023 Rule 15.0.2 (Advisory)
// User-declared, non-deleted copy and move member functions of a class should have appropriate signatures
//
// Example 2: Copy assignment that returns by value

// BEGIN violation
struct ByValue {
    ByValue operator=(const ByValue& other);
};
// END violation

// BEGIN compliant
struct ByReference {
    ByReference& operator=(const ByReference& other);
};
// END compliant
