// MISRA C++:2023 Rule 8.2.6 (Required)
// An object with integral, enumerated, or pointer to void type shall not be cast to a pointer type
//
// Example 1: Integer converted to a pointer

#include <cstdint>

// BEGIN violation
int* integer_to_pointer(std::uintptr_t address) {
    return reinterpret_cast<int*>(address);
}
// END violation

// BEGIN compliant
int* identity_pointer(int* p) {
    return p;
}
// END compliant
