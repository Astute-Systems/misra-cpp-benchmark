// MISRA C++:2023 Rule 12.3.1 (Required)
// The union keyword shall not be used
//
// Example 1: Named union

// BEGIN violation
union Number {
    int i;
    float f;
};
// END violation

// BEGIN compliant
#include <variant>

using SafeNumber = std::variant<int, float>;
// END compliant
