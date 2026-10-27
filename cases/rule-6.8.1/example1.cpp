// MISRA C++:2023 Rule 6.8.1 (Required)
// An object shall not be accessed outside of its lifetime
//
// Example 1: Object used after it was deleted

// BEGIN violation
int use_after_delete() {
    int* p = new int(1);
    delete p;
    return *p;
}
// END violation

// BEGIN compliant
int use_before_delete() {
    int* p = new int(1);
    int v = *p;
    delete p;
    return v;
}
// END compliant
