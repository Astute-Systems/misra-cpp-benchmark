// MISRA C++:2023 Rule 18.5.1 (Advisory)
// A noexcept function should not attempt to propagate an exception to the calling function
//
// Example 2: noexcept function that calls a throwing function

void may_throw();

// BEGIN violation
void noexcept_propagates() noexcept {
    may_throw();
}
// END violation

// BEGIN compliant
void noexcept_contains() noexcept {
    try {
        may_throw();
    } catch (...) {
    }
}
// END compliant
