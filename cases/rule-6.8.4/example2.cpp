// MISRA C++:2023 Rule 6.8.4 (Advisory)
// Member functions returning references to their object should be ref-qualified appropriately
//
// Example 2: Const member function returns a const reference to itself

// BEGIN violation
struct Node {
    const Node& view() const {
        return *this;
    }
};
// END violation

// BEGIN compliant
struct QualifiedNode {
    const QualifiedNode& view() const& {
        return *this;
    }
};
// END compliant
