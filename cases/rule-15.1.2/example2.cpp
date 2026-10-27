// MISRA C++:2023 Rule 15.1.2 (Advisory)
// All constructors of a class should explicitly initialize all of its virtual base classes and immediate base classes
//
// Example 2: Copy constructor that omits the base class copy

// BEGIN violation
struct Base {
    Base() = default;
    Base(const Base&) = default;
};

struct Derived : Base {
    Derived() = default;
    Derived(const Derived&) {}
};
// END violation

// BEGIN compliant
struct Base2 {
    Base2() = default;
    Base2(const Base2&) = default;
};

struct Derived2 : Base2 {
    Derived2() = default;
    Derived2(const Derived2& other) : Base2(other) {}
};
// END compliant
