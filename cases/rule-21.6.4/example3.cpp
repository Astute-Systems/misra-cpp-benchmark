// MISRA C++:2023 Rule 21.6.4 (Required)
// If a project defines an unsized version of a global operator delete, the corresponding sized operator delete shall be defined in the same file, and vice versa
//
// Example 3: Both forms defined together (compliant counterpart)

#include <cstddef>
#include <cstdlib>

// BEGIN compliant
void operator delete(void* p) noexcept {
    std::free(p);
}

void operator delete(void* p, std::size_t) noexcept {
    std::free(p);
}
// END compliant
