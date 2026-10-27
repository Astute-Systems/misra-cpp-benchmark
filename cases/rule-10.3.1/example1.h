#ifndef RULE_10_3_1_EXAMPLE1_H
#define RULE_10_3_1_EXAMPLE1_H

// BEGIN violation
namespace {
constexpr int hidden_in_header = 1;
}
// END violation

// BEGIN compliant
namespace named_in_header {
constexpr int value = 1;
}
// END compliant

#endif
