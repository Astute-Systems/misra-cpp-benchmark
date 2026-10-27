// MISRA C++:2023 Rule 23.11.1 (Advisory)
// The raw pointer constructors of std::shared_ptr and std::unique_ptr should not be used
//
// Example 2: unique_ptr built from a raw pointer

#include <memory>

// BEGIN violation
std::unique_ptr<int> raw_unique() {
    return std::unique_ptr<int>(new int(1));
}
// END violation

// BEGIN compliant
std::unique_ptr<int> made_unique() {
    return std::make_unique<int>(1);
}
// END compliant
