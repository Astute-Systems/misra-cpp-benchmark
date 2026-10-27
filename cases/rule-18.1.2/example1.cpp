// MISRA C++:2023 Rule 18.1.2 (Required)
// An empty throw shall only occur within the compound-statement of a catch handler
//
// Example 1: Empty throw outside of a handler

// BEGIN violation
void rethrow_outside_handler() {
    throw;
}
// END violation

// BEGIN compliant
void rethrow_inside_handler() {
    try {
        throw 1;
    } catch (...) {
        throw;
    }
}
// END compliant
