// MISRA C++:2023 Rule 15.1.2 (Advisory)
// All constructors of a class should explicitly initialize all of its virtual base classes and immediate base classes
//
// Example 1: Constructor that does not initialize its base class

// BEGIN violation
struct Parent {
    Parent();
};

struct Child : Parent {
    Child() {}
};
// END violation

// BEGIN compliant
struct Parent2 {
    Parent2();
};

struct Child2 : Parent2 {
    Child2() : Parent2() {}
};
// END compliant
