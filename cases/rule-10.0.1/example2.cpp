// MISRA C++:2023 Rule 10.0.1 (Advisory)
// A declaration should not declare more than one variable or member variable
//
// Example 2: Several member variables in one declaration

// BEGIN violation
struct Coordinates {
    int x, y;
};
// END violation

// BEGIN compliant
struct SeparateCoordinates {
    int x;
    int y;
};
// END compliant
