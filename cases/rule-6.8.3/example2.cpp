// MISRA C++:2023 Rule 6.8.3 (Required)
// An assignment operator shall not assign the address of an object with automatic storage duration to an object with a greater lifetime
//
// Example 2: Address of a local stored in a member

// BEGIN violation
struct Holder {
    int* p;
    void set() {
        int local = 0;
        p = &local;
    }
};
// END violation

// BEGIN compliant
struct SafeHolder {
    int* p;
    int stored;
    void set() {
        stored = 0;
        p = &stored;
    }
};
// END compliant
