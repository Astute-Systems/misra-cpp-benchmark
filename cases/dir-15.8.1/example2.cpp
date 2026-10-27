// MISRA C++:2023 Directive 15.8.1 (Required)
// User-provided copy assignment operators and move assignment operators shall handle self-assignment
//
// Example 2: Move assignment without a self-assignment check

// BEGIN violation
struct Owner {
    int* data = nullptr;
    Owner& operator=(Owner&& other) noexcept {
        delete data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }
};
// END violation

// BEGIN compliant
struct SafeOwner {
    int* data = nullptr;
    SafeOwner& operator=(SafeOwner&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};
// END compliant
