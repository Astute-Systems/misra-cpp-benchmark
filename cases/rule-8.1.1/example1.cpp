// MISRA C++:2023 Rule 8.1.1 (Required)
// A non-transient lambda shall not implicitly capture this
//
// Example 1: Returned lambda captures this implicitly

// BEGIN violation
struct Source {
    int v;
    auto getter() {
        return [=] { return v; };
    }
};
// END violation

// BEGIN compliant
struct SafeSource {
    int v;
    auto getter() {
        return [value = v] { return value; };
    }
};
// END compliant
