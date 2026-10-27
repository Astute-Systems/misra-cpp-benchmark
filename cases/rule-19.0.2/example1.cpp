// MISRA C++:2023 Rule 19.0.2 (Required)
// Function-like macros shall not be defined
//
// Example 1: Function-like macro that squares its argument

// BEGIN violation
#define SQUARE(x) ((x) * (x))

int squared(int v) {
    return SQUARE(v);
}
// END violation

// BEGIN compliant
constexpr int square(int x) {
    return x * x;
}

int squared_function(int v) {
    return square(v);
}
// END compliant
