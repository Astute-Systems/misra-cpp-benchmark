// MISRA C++:2023 Rule 15.1.1 (Required)
// An object's dynamic type shall not be used from within its constructor or destructor
//
// Example 2: typeid on *this inside a destructor

#include <typeinfo>

// BEGIN violation
struct Tracked {
    virtual ~Tracked() { name = typeid(*this).name(); }
    const char* name = nullptr;
};
// END violation

// BEGIN compliant
struct UntrackedName {
    virtual ~UntrackedName() { name = "UntrackedName"; }
    const char* name = nullptr;
};
// END compliant
