// MISRA C++:2023 Rule 8.2.6 (Required)
// An object with integral, enumerated, or pointer to void type shall not be cast to a pointer type
//
// Example 2: void* converted to an object pointer

// BEGIN violation
int* void_to_object(void* p) {
    return static_cast<int*>(p);
}
// END violation

// BEGIN compliant
struct Parent2 {};
struct Child2 : Parent2 {};

Child2* related_pointer(Parent2* p) {
    return static_cast<Child2*>(p);
}
// END compliant
