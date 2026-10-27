// MISRA C++:2023 Rule 28.6.4 (Required)
// The result of std::remove, std::remove_if, std::unique, std::unique_ptr::release, and empty shall be used
//
// Example 1: Discarded result of std::remove

#include <algorithm>
#include <vector>

// BEGIN violation
void discard_remove(std::vector<int>& v) {
    std::remove(v.begin(), v.end(), 2);
}
// END violation

// BEGIN compliant
void erase_remove(std::vector<int>& v) {
    v.erase(std::remove(v.begin(), v.end(), 2), v.end());
}
// END compliant
