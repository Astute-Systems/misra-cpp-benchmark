// MISRA C++:2023 Rule 18.5.1 (Advisory)
// A noexcept function should not attempt to propagate an exception to the calling function
//
// Example 1: noexcept function that throws

// BEGIN violation
void noexcept_throws() noexcept {
    throw 1;
}
// END violation

// BEGIN compliant
void noexcept_handles() noexcept {
    try {
        throw 1;
    } catch (...) {
    }
}
// END compliant
