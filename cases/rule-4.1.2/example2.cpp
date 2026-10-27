// MISRA C++:2023 Rule 4.1.2 (Advisory)
// Deprecated features should not be used
//
// Example 2: Deprecated std::iterator base class

#include <cstddef>
#include <iterator>

// BEGIN violation
struct OldIterator : std::iterator<std::input_iterator_tag, int> {
    int operator*() const { return 0; }
};
// END violation

// BEGIN compliant
struct NewIterator {
    using iterator_category = std::input_iterator_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;
    using pointer = const int*;
    using reference = int;
    int operator*() const { return 0; }
};
// END compliant
