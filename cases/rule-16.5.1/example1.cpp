// MISRA C++:2023 Rule 16.5.1 (Required)
// The logical AND and logical OR operators shall not be overloaded
//
// Example 1: Overloaded logical AND

// BEGIN violation
struct Condition {
    bool value;
};

bool operator&&(Condition a, Condition b);
// END violation

// BEGIN compliant
struct Condition2 {
    bool value;
};

bool operator==(Condition2 a, Condition2 b);
// END compliant
