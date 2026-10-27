// MISRA C++:2023 Rule 28.6.2 (Required)
// Forwarding references and std::forward shall be used together
//
// Example 1: Forwarding reference that is not forwarded

void consume(const int&);

// BEGIN violation
template <typename T>
void not_forwarded(T&& v) {
    consume(v);
}
// END violation

// BEGIN compliant
#include <utility>

template <typename T>
void forwarded(T&& v) {
    consume(std::forward<T>(v));
}
// END compliant
