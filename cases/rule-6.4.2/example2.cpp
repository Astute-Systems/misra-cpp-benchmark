// MISRA C++:2023 Rule 6.4.2 (Required)
// Derived classes shall not conceal functions that are inherited from their bases
//
// Example 2: Derived function hides a non-virtual base function

struct Plain {
    void set(int);
};

// BEGIN violation
struct PlainHiding : Plain {
    void set(double);
};
// END violation

// BEGIN compliant
struct PlainRevealing : Plain {
    using Plain::set;
    void set(double);
};
// END compliant
