// MISRA C++:2023 Rule 15.1.4 (Advisory)
// All direct, non-static data members of a class should be initialized before the class object is accessible
//
// Example 1: Constructor that leaves members uninitialised

// BEGIN violation
struct Point {
    int x;
    int y;
    Point() {}
};
// END violation

// BEGIN compliant
struct InitialisedPoint {
    int x;
    int y;
    InitialisedPoint() : x(0), y(0) {}
};
// END compliant
