// MISRA C++:2023 Rule 8.2.9 (Required)
// The operand to typeid shall not be an expression of polymorphic class type
//
// Example 2: typeid applied to a dereferenced pointer to a polymorphic class

#include <typeinfo>

struct Poly2 {
    virtual ~Poly2() = default;
};

// BEGIN violation
const std::type_info& dereferenced_type(Poly2* p) {
    return typeid(*p);
}
// END violation

// BEGIN compliant
const std::type_info& pointer_type() {
    return typeid(Poly2*);
}
// END compliant
