// MISRA C++:2023 Rule 6.8.1 (Required)
// An object shall not be accessed outside of its lifetime
//
// Example 2: Pointer used after the object went out of scope

// BEGIN violation
int use_after_scope() {
    int* p = nullptr;
    {
        int inner = 1;
        p = &inner;
    }
    return *p;
}
// END violation

// BEGIN compliant
int use_in_scope() {
    int outer = 1;
    int* p = &outer;
    return *p;
}
// END compliant
