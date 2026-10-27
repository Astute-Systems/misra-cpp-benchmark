// MISRA C++:2023 Rule 8.1.1 (Required)
// A non-transient lambda shall not implicitly capture this
//
// Example 2: Lambda stored in std::function captures this by default reference

#include <functional>

// BEGIN violation
struct Stored {
    int v;
    std::function<int()> make() {
        return [&] { return v; };
    }
};
// END violation

// BEGIN compliant
struct StoredSafe {
    int v;
    std::function<int()> make() {
        return [value = v] { return value; };
    }
};
// END compliant
