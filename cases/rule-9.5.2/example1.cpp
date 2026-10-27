// MISRA C++:2023 Rule 9.5.2 (Required)
// A for-range-initializer shall contain at most one function call
//
// Example 1: Range-for initializer with two function calls

#include <vector>

struct Box {
    std::vector<int> values;
    const std::vector<int>& items() const { return values; }
};

Box make_box();

// BEGIN violation
int two_calls_in_range() {
    int sum = 0;
    for (int v : make_box().items()) {
        sum += v;
    }
    return sum;
}
// END violation

// BEGIN compliant
int one_call_in_range() {
    int sum = 0;
    Box b = make_box();
    for (int v : b.values) {
        sum += v;
    }
    return sum;
}
// END compliant
