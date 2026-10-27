// MISRA C++:2023 Rule 28.6.4 (Required)
// The result of std::remove, std::remove_if, std::unique, std::unique_ptr::release, and empty shall be used
//
// Example 2: Discarded result of release and empty

#include <memory>
#include <vector>

// BEGIN violation
void discard_release(std::unique_ptr<int>& p) {
    p.release();
}

void discard_empty(const std::vector<int>& v) {
    v.empty();
}
// END violation

// BEGIN compliant
int* keep_release(std::unique_ptr<int>& p) {
    return p.release();
}

bool keep_empty(const std::vector<int>& v) {
    return v.empty();
}
// END compliant
