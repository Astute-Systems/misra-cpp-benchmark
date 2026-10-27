// MISRA C++:2023 Rule 26.3.1 (Advisory)
// std::vector should not be specialized with bool
//
// Example 2: vector<bool> hidden behind an alias

#include <vector>

// BEGIN violation
using BitVector = std::vector<bool>;

BitVector make_bits() {
    return BitVector();
}
// END violation

// BEGIN compliant
using IntVector = std::vector<int>;

IntVector make_ints() {
    return IntVector();
}
// END compliant
