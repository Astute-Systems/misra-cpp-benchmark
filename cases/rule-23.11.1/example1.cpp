// MISRA C++:2023 Rule 23.11.1 (Advisory)
// The raw pointer constructors of std::shared_ptr and std::unique_ptr should not be used
//
// Example 1: shared_ptr built from a raw pointer

#include <memory>

// BEGIN violation
std::shared_ptr<int> raw_shared() {
    return std::shared_ptr<int>(new int(1));
}
// END violation

// BEGIN compliant
std::shared_ptr<int> made_shared() {
    return std::make_shared<int>(1);
}
// END compliant
