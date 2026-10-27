// MISRA C++:2023 Rule 6.4.2 (Required)
// Derived classes shall not conceal functions that are inherited from their bases
//
// Example 1: Derived overload hides the inherited virtual function

struct Base {
    virtual ~Base() = default;
    virtual void apply(int);
};

// BEGIN violation
struct Hiding : Base {
    void apply();
};
// END violation

// BEGIN compliant
struct Revealing : Base {
    using Base::apply;
    void apply();
};
// END compliant
