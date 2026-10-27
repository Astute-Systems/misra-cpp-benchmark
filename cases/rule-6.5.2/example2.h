#ifndef RULE_6_5_2_EXAMPLE2_H
#define RULE_6_5_2_EXAMPLE2_H

// BEGIN violation
static int static_counter = 0;
// END violation

// BEGIN compliant
inline int inline_counter = 0;
constexpr int kLimit = 4;
// END compliant

#endif
