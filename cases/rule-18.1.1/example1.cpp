// MISRA C++:2023 Rule 18.1.1 (Required)
// An exception object shall not have pointer type
//
// Example 1: Throwing a pointer to a heap object

// BEGIN violation
void throw_heap_pointer() {
    throw new int(1);
}
// END violation

// BEGIN compliant
#include <stdexcept>

void throw_object() {
    throw std::runtime_error("failure");
}
// END compliant
