// MISRA C++:2023 Rule 14.1.1 (Advisory)
// Non-static data members should be either all private or all public
//
// Example 1: Public and private data members mixed

// BEGIN violation
class Mixed {
public:
    int open;

private:
    int hidden;
};
// END violation

// BEGIN compliant
class AllPrivate {
    int a;
    int b;
};
// END compliant
