// MISRA C++:2023 Rule 28.6.2 (Required)
// Forwarding references and std::forward shall be used together
//
// Example 2: std::forward applied to a parameter that is not a forwarding reference

#include <utility>

void consume2(const int&);

// BEGIN violation
template <typename T>
void forward_const_reference(const T& v) {
    consume2(std::forward<T>(v));
}
// END violation

// BEGIN compliant
template <typename T>
void pass_const_reference(const T& v) {
    consume2(v);
}
// END compliant
