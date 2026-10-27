// MISRA C++:2023 Rule 21.6.2 (Required)
// Dynamic memory shall be managed automatically
//
// Example 1: Explicit delete

// BEGIN violation
void explicit_delete(int* p) {
    delete p;
}
// END violation

// BEGIN compliant
#include <memory>

void managed_pointer(std::unique_ptr<int> p) {
    static_cast<void>(p);
}
// END compliant
