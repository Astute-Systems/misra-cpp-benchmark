// MISRA C++:2023 Rule 8.2.9 (Required)
// The operand to typeid shall not be an expression of polymorphic class type
//
// Example 1: typeid applied to a polymorphic expression

#include <typeinfo>

struct Poly {
    virtual ~Poly() = default;
};

// BEGIN violation
const std::type_info& dynamic_type(Poly& p) {
    return typeid(p);
}
// END violation

// BEGIN compliant
const std::type_info& static_type() {
    return typeid(Poly);
}
// END compliant
