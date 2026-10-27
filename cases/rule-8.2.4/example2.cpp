// MISRA C++:2023 Rule 8.2.4 (Required)
// Casts shall not be performed between a pointer to function and any other type
//
// Example 2: Function pointer converted to a pointer of another function type

int one_argument(int);

// BEGIN violation
int (*retyped_function())(int, int) {
    return reinterpret_cast<int (*)(int, int)>(&one_argument);
}
// END violation

// BEGIN compliant
int (*same_function_type())(int) {
    return &one_argument;
}
// END compliant
