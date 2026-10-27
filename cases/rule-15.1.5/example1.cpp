// MISRA C++:2023 Rule 15.1.5 (Required)
// A class shall only define an initializer-list constructor when it is the only constructor
//
// Example 1: initializer_list constructor next to another constructor

#include <initializer_list>

// BEGIN violation
struct List {
    List(std::initializer_list<int> values);
    List(int count, int value);
};
// END violation

// BEGIN compliant
struct OnlyList {
    OnlyList(std::initializer_list<int> values);
};
// END compliant
