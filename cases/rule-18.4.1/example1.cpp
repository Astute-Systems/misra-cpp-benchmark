// MISRA C++:2023 Rule 18.4.1 (Required)
// Exception-unfriendly functions shall be noexcept
//
// Example 1: Destructor that may throw

// BEGIN violation
struct Releasing {
    ~Releasing() noexcept(false) {}
};
// END violation

// BEGIN compliant
struct SafeReleasing {
    ~SafeReleasing() noexcept {}
};
// END compliant
