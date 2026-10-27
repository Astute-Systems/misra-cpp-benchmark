// MISRA C++:2023 Rule 8.2.11 (Required)
// An argument passed via ellipsis shall have an appropriate type
//
// Example 2: Class with a non-trivial copy constructor passed through an ellipsis

// COMPILE-FLAGS: -Wno-non-pod-varargs
int variadic2(int count, ...);

struct Copied {
    int value;
    Copied() = default;
    Copied(const Copied& other) : value(other.value) {}
};

// BEGIN violation
int pass_copied_object() {
    return variadic2(1, Copied());
}
// END violation

// BEGIN compliant
int pass_scalar_value() {
    return variadic2(1, 42);
}
// END compliant
