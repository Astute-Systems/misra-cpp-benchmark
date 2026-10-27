// MISRA C++:2023 Rule 28.6.3 (Required)
// A variable shall not be referenced while it has potentially moved-from state
//
// Example 1: Variable read after std::move

#include <string>
#include <utility>

// BEGIN violation
std::size_t use_after_move() {
    std::string a = "x";
    std::string b = std::move(a);
    return a.size() + b.size();
}
// END violation

// BEGIN compliant
std::size_t reassign_after_move() {
    std::string a = "x";
    std::string b = std::move(a);
    a = "y";
    return a.size() + b.size();
}
// END compliant
