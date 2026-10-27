// MISRA C++:2023 Rule 15.1.4 (Advisory)
// All direct, non-static data members of a class should be initialized before the class object is accessible
//
// Example 2: Constructor that initialises only some members

// BEGIN violation
struct Partial {
    int a;
    int b;
    Partial() : a(0) {}
};
// END violation

// BEGIN compliant
struct Complete {
    int a;
    int b;
    Complete() : a(0), b(0) {}
};
// END compliant
