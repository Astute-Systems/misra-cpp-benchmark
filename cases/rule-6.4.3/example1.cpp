// MISRA C++:2023 Rule 6.4.3 (Required)
// An identifier that is present in a dependent base shall not be resolved by unqualified lookup
//
// Example 1: Unqualified call resolves to a global function instead of the dependent base member

void hello() {}

template <typename T>
struct Base {
    void hello() {}
};

// BEGIN violation
template <typename T>
struct Hidden : Base<T> {
    void run() {
        hello();
    }
};
// END violation

// BEGIN compliant
template <typename T>
struct Qualified : Base<T> {
    void run() {
        this->hello();
    }
};
// END compliant
