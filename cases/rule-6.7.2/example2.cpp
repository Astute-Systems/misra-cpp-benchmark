// MISRA C++:2023 Rule 6.7.2 (Required)
// Global variables shall not be used
//
// Example 2: Mutable variable in a named namespace

// BEGIN violation
namespace config {
int level = 3;
}
// END violation

// BEGIN compliant
namespace settings {
constexpr int level = 3;
}
// END compliant
