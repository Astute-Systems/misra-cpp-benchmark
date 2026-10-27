// MISRA C++:2023 Rule 16.5.2 (Required)
// The address-of operator shall not be overloaded
//
// Example 1: Overloaded unary address-of as a member

// BEGIN violation
struct Proxy {
    Proxy* operator&();
};
// END violation

// BEGIN compliant
struct Plain {
    int value;
};
// END compliant
