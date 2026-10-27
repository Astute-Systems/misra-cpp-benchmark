// MISRA C++:2023 Rule 13.3.2 (Required)
// Parameters in an overriding virtual function shall not specify different default arguments
//
// Example 1: Overrider changes a default argument

// BEGIN violation
struct Shape {
    virtual ~Shape() = default;
    virtual void scale(int factor = 1);
};

struct Square : Shape {
    void scale(int factor = 2) override;
};
// END violation

// BEGIN compliant
struct Circle {
    virtual ~Circle() = default;
    virtual void scale(int factor = 1);
};

struct Disc : Circle {
    void scale(int factor = 1) override;
};
// END compliant
