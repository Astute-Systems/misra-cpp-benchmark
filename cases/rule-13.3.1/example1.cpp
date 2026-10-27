// MISRA C++:2023 Rule 13.3.1 (Required)
// User-declared member functions shall use the virtual, override and final specifiers appropriately
//
// Example 1: Overriding function without override

// BEGIN violation
struct Base {
    virtual ~Base() = default;
    virtual void run();
};

struct Derived : Base {
    void run();
};
// END violation

// BEGIN compliant
struct GoodBase {
    virtual ~GoodBase() = default;
    virtual void run();
};

struct GoodDerived : GoodBase {
    void run() override;
};
// END compliant
