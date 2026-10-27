// MISRA C++:2023 Rule 13.3.4 (Required)
// A comparison of a potentially virtual pointer to member function shall only be with nullptr
//
// Example 1: Pointer to virtual member function compared with another pointer

// BEGIN violation
struct Target {
    virtual ~Target() = default;
    virtual void f();
    void g();
};

bool compare_member_pointers() {
    void (Target::*a)() = &Target::f;
    return a == &Target::g;
}
// END violation

// BEGIN compliant
struct Target2 {
    virtual ~Target2() = default;
    virtual void f();
};

bool compare_with_nullptr() {
    void (Target2::*a)() = &Target2::f;
    return a == nullptr;
}
// END compliant
