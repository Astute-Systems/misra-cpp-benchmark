#ifndef RULE_6_5_2_EXAMPLE1_H
#define RULE_6_5_2_EXAMPLE1_H

// BEGIN violation
static int static_helper(int v) {
    return v + 1;
}
// END violation

// BEGIN compliant
inline int inline_helper(int v) {
    return v + 1;
}
// END compliant

#endif
