// MISRA C++:2023 Rule 6.2.3 (Required)
// The source code used to implement an entity shall appear only once
//
// Example 1: Function and class text duplicated in two source files

// BEGIN violation
struct Vec2 {
    int x;
    int y;
};

inline int dot(const Vec2& a, const Vec2& b) {
    return a.x * b.x + a.y * b.y;
}
// END violation
