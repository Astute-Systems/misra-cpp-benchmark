// MISRA C++:2023 Rule 8.2.5 (Required)
// reinterpret_cast shall not be used
//
// Example 2: reinterpret_cast to a byte pointer

// BEGIN violation
unsigned char* as_bytes(int* i) {
    return reinterpret_cast<unsigned char*>(i);
}
// END violation

// BEGIN compliant
struct Parent {};
struct Child : Parent {};

Child* downcast(Parent* p) {
    return static_cast<Child*>(p);
}
// END compliant
