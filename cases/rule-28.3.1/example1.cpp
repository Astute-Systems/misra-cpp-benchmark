// MISRA C++:2023 Rule 28.3.1 (Required)
// Predicates shall not have persistent side effects
//
// Example 1: Predicate that modifies a captured counter

#include <algorithm>
#include <vector>

// BEGIN violation
long count_with_side_effect(const std::vector<int>& v) {
    int calls = 0;
    return std::count_if(v.begin(), v.end(), [&calls](int x) {
        ++calls;
        return x > calls;
    });
}
// END violation

// BEGIN compliant
long count_pure(const std::vector<int>& v) {
    return std::count_if(v.begin(), v.end(), [](int x) { return x > 2; });
}
// END compliant
