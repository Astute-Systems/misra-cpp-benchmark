// MISRA C++:2023 Rule 16.5.2 (Required)
// The address-of operator shall not be overloaded
//
// Example 2: Overloaded unary address-of as a free function

// BEGIN violation
struct Handle {};

Handle* operator&(Handle& h);
// END violation

// BEGIN compliant
struct Handle2 {};

Handle2* get_address(Handle2& h);
// END compliant
