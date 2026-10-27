// MISRA C++:2023 Rule 10.2.3 (Required)
// The numeric value of an unscoped enumeration with no fixed underlying type shall not be used
//
// Example 1: Numeric value of an unscoped enumeration

// BEGIN violation
enum Direction { North, South };

int direction_value() {
    int v = South + 1;
    return v;
}
// END violation

// BEGIN compliant
enum class Heading : int { North, South };

int heading_value() {
    return static_cast<int>(Heading::South) + 1;
}
// END compliant
