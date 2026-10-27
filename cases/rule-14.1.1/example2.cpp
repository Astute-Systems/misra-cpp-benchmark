// MISRA C++:2023 Rule 14.1.1 (Advisory)
// Non-static data members should be either all private or all public
//
// Example 2: Public and protected data members mixed

// BEGIN violation
struct MixedProtected {
    int open;

protected:
    int guarded;
};
// END violation

// BEGIN compliant
struct AllPublic {
    int open;
    int other;
};
// END compliant
