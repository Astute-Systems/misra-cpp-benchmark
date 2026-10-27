// MISRA C++:2023 Rule 8.2.11 (Required)
// An argument passed via ellipsis shall have an appropriate type
//
// Example 2: Narrow arithmetic types passed through an ellipsis

int variadic2(int count, ...);

// BEGIN violation
int pass_promoted_types() {
    short s = 1;
    float f = 2.0F;
    return variadic2(2, s, f);
}
// END violation

// BEGIN compliant
int pass_unpromoted_types() {
    int i = 1;
    double d = 2.0;
    return variadic2(2, i, d);
}
// END compliant
