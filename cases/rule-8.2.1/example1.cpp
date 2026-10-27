// MISRA C++:2023 Rule 8.2.1 (Required)
// A virtual base class shall only be cast to a derived class by means of dynamic_cast
//
// Example 1: Virtual base converted to a derived class without dynamic_cast

struct VBase {
    virtual ~VBase() = default;
};

struct VDerived : virtual VBase {};

// BEGIN violation
VDerived* unchecked_downcast(VBase* b) {
    return reinterpret_cast<VDerived*>(b);
}
// END violation

// BEGIN compliant
VDerived* checked_downcast(VBase* b) {
    return dynamic_cast<VDerived*>(b);
}
// END compliant
