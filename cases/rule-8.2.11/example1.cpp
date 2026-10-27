// MISRA C++:2023 Rule 8.2.11 (Required)
// An argument passed via ellipsis shall have an appropriate type
//
// Example 1: Polymorphic class passed through an ellipsis

// COMPILE-FLAGS: -Wno-non-pod-varargs
// Clang rejects this call by default ("call will abort at runtime"); the flag
// above turns that diagnostic off so the example can be analysed.
int variadic(int count, ...);

struct Shape {
    int sides;
    virtual void draw();
};

struct Plain {
    int sides;
};

// BEGIN violation
int pass_polymorphic_object() {
    return variadic(1, Shape());
}
// END violation

// BEGIN compliant
int pass_trivial_object() {
    return variadic(1, Plain());
}
// END compliant
