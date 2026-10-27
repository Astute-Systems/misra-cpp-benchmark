// MISRA C++:2023 Rule 15.0.2 (Advisory)
// User-declared, non-deleted copy and move member functions of a class should have appropriate signatures
//
// Example 1: Copy operations that take a non-const reference

// BEGIN violation
struct Mutable {
    Mutable() = default;
    Mutable(Mutable& other);
    Mutable& operator=(Mutable& other);
};
// END violation

// BEGIN compliant
struct Constant {
    Constant() = default;
    Constant(const Constant& other);
    Constant& operator=(const Constant& other);
};
// END compliant
