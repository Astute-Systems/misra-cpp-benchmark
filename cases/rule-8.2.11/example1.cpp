// MISRA C++:2023 Rule 8.2.11 (Required)
// An argument passed via ellipsis shall have an appropriate type
//
// Example 1: Class object passed through an ellipsis

int variadic(int count, ...);

struct Pair {
    int a;
    int b;
};

// BEGIN violation
int pass_class_object() {
    Pair p{1, 2};
    return variadic(1, p);
}
// END violation

// BEGIN compliant
int pass_scalar() {
    return variadic(1, 42);
}
// END compliant
