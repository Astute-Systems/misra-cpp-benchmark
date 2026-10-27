// MISRA C++:2023 Rule 21.6.4 (Required)
// If a project defines an unsized version of a global operator delete, the corresponding sized operator delete shall be defined in the same file, and vice versa
//
// Example 2: Sized operator delete without the unsized form

#include <cstddef>
#include <cstdlib>

// BEGIN violation
void operator delete(void* p, std::size_t) noexcept {
    std::free(p);
}
// END violation
