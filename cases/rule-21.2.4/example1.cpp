// MISRA C++:2023 Rule 21.2.4 (Required)
// The macro offsetof shall not be used
//
// Example 1: offsetof

#include <cstddef>

struct Record {
    int a;
    int b;
};

// BEGIN violation
std::size_t offset_of_b() {
    return offsetof(Record, b);
}
// END violation

// BEGIN compliant
std::size_t size_of_record() {
    return sizeof(Record);
}
// END compliant
