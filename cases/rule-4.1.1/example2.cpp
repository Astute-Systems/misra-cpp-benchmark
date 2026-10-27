// MISRA C++:2023 Rule 4.1.1 (Required)
// A program shall conform to ISO/IEC 14882:2017 (C++17)
//
// Example 2: Designated initializers (C++20 feature in a C++17 program)

struct Point {
    int x;
    int y;
};

// BEGIN violation
Point designated() {
    Point p{.x = 1, .y = 2};
    return p;
}
// END violation

// BEGIN compliant
Point positional() {
    Point p{1, 2};
    return p;
}
// END compliant
