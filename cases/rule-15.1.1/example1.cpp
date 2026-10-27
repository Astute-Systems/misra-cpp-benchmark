// MISRA C++:2023 Rule 15.1.1 (Required)
// An object's dynamic type shall not be used from within its constructor or destructor
//
// Example 1: Virtual call from a constructor

// BEGIN violation
struct Component {
    Component() { init(); }
    virtual ~Component() = default;
    virtual void init();
};
// END violation

// BEGIN compliant
struct StaticComponent {
    StaticComponent() { init_base(); }
    virtual ~StaticComponent() = default;
    void init_base();
};
// END compliant
