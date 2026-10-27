// BEGIN violation
struct Vec2 {
    int x;
    int y;
};

inline int dot(const Vec2& a, const Vec2& b) {
    return a.x * b.x + a.y * b.y;
}
// END violation
