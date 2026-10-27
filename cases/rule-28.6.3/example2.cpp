// MISRA C++:2023 Rule 28.6.3 (Required)
// A variable shall not be referenced while it has potentially moved-from state
//
// Example 2: Container used after being moved into a function

#include <utility>
#include <vector>

void sink(std::vector<int>);

// BEGIN violation
void use_after_sink() {
    std::vector<int> v(4);
    sink(std::move(v));
    v.push_back(1);
}
// END violation

// BEGIN compliant
void no_use_after_sink() {
    std::vector<int> v(4);
    sink(std::move(v));
}
// END compliant
