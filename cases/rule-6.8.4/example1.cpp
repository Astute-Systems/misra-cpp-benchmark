// MISRA C++:2023 Rule 6.8.4 (Advisory)
// Member functions returning references to their object should be ref-qualified appropriately
//
// Example 1: Member function returns *this without a ref-qualifier

// BEGIN violation
struct Builder {
    Builder& self() {
        return *this;
    }
};
// END violation

// BEGIN compliant
struct QualifiedBuilder {
    QualifiedBuilder& self() & {
        return *this;
    }
};
// END compliant
