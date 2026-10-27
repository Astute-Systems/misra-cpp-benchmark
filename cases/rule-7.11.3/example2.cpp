// MISRA C++:2023 Rule 7.11.3 (Required)
// A conversion to pointer-to-function from a function type or class type shall only occur in appropriate contexts
//
// Example 2: Function name converted to bool

void callback();

// BEGIN violation
bool function_as_condition() {
    if (callback) {
        return true;
    }
    return false;
}
// END violation

// BEGIN compliant
bool pointer_as_condition(void (*fp)()) {
    return fp != nullptr;
}
// END compliant
