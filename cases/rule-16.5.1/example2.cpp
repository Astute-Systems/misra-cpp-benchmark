// MISRA C++:2023 Rule 16.5.1 (Required)
// The logical AND and logical OR operators shall not be overloaded
//
// Example 2: Overloaded logical OR as a member

// BEGIN violation
struct Flag {
    bool value;
    bool operator||(const Flag& other) const;
};
// END violation

// BEGIN compliant
struct Flag2 {
    bool value;
    bool operator==(const Flag2& other) const;
};
// END compliant
