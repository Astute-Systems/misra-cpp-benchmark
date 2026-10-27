// MISRA C++:2023 Rule 13.3.1 (Required)
// User-declared member functions shall use the virtual, override and final specifiers appropriately
//
// Example 2: virtual and override on the same declaration

// BEGIN violation
struct Base2 {
    virtual ~Base2() = default;
    virtual void run();
};

struct Derived2 : Base2 {
    virtual void run() override;
};
// END violation

// BEGIN compliant
struct Base3 {
    virtual ~Base3() = default;
    virtual void run();
};

struct Derived3 : Base3 {
    void run() override;
};
// END compliant
