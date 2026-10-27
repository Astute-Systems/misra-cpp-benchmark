// MISRA C++:2023 Rule 28.3.1 (Required)
// Predicates shall not have persistent side effects
//
// Example 2: Mutable predicate with its own state

#include <algorithm>
#include <vector>

// BEGIN violation
bool find_third(const std::vector<int>& v) {
    return std::find_if(v.begin(), v.end(), [seen = 0](int) mutable {
               return ++seen == 3;
           }) != v.end();
}
// END violation

// BEGIN compliant
bool find_negative(const std::vector<int>& v) {
    return std::find_if(v.begin(), v.end(), [](int x) { return x < 0; }) != v.end();
}
// END compliant
