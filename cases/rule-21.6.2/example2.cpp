// MISRA C++:2023 Rule 21.6.2 (Required)
// Dynamic memory shall be managed automatically
//
// Example 2: Explicit delete[] and free

#include <cstdlib>

// BEGIN violation
void explicit_array_delete(int* p) {
    delete[] p;
}

void explicit_free(void* p) {
    std::free(p);
}
// END violation

// BEGIN compliant
#include <vector>

void managed_container(std::vector<int> v) {
    static_cast<void>(v);
}
// END compliant
