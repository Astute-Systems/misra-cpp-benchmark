// MISRA C++:2023 Rule 19.0.2 (Required)
// Function-like macros shall not be defined
//
// Example 2: Function-like macro that selects a maximum

// BEGIN violation
#define MAX_OF(a, b) (((a) > (b)) ? (a) : (b))

int larger(int a, int b) {
    return MAX_OF(a, b);
}
// END violation

// BEGIN compliant
#define LIMIT 100

int limited(int a) {
    return a < LIMIT ? a : LIMIT;
}
// END compliant
