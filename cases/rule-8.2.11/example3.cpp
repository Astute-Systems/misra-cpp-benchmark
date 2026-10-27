// MISRA C++:2023 Rule 8.2.11 (Required)
// An argument passed via ellipsis shall have an appropriate type
//
// Example 3: Class argument inside sizeof is never evaluated (compliant counterpart)

int variadic3(int count, ...);

struct Unevaluated {
    virtual void f();
};

// BEGIN compliant
unsigned long unevaluated_argument() {
    return sizeof(variadic3(1, Unevaluated()));
}
// END compliant
