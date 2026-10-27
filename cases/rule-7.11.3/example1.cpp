// MISRA C++:2023 Rule 7.11.3 (Required)
// A conversion to pointer-to-function from a function type or class type shall only occur in appropriate contexts
//
// Example 1: Relational comparison of function addresses

void first();
void second();

// BEGIN violation
bool function_order() {
    return &first < &second;
}
// END violation

// BEGIN compliant
bool function_identity() {
    return &first == &second;
}
// END compliant
