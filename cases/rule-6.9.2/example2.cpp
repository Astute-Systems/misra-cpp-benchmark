// MISRA C++:2023 Rule 6.9.2 (Advisory)
// The names of the standard signed integer types and standard unsigned integer types should not be used
//
// Example 2: Built-in integer type names in a class

// BEGIN violation
struct BuiltinFields {
    short a;
    long b;
};
// END violation

// BEGIN compliant
#include <cstdint>

struct FixedFields {
    std::int16_t a;
    std::int64_t b;
};
// END compliant
