// BEGIN compliant
#ifndef RULE_6_2_3_EXAMPLE3_H
#define RULE_6_2_3_EXAMPLE3_H

struct Vec2b {
    int x;
    int y;
};

inline int dot2(const Vec2b& a, const Vec2b& b) {
    return a.x * b.x + a.y * b.y;
}

#endif
// END compliant
