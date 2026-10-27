// MISRA C++:2023 Rule 6.4.1 (Required)
// A variable declared in an inner scope shall not hide a variable declared in an outer scope
//
// Example 1: Local variable hides another local variable

// BEGIN violation
int shadowed_local() {
    int x = 1;
    {
        int x = 2;
        static_cast<void>(x);
    }
    return x;
}
// END violation

// BEGIN compliant
int distinct_locals() {
    int x = 1;
    {
        int y = 2;
        static_cast<void>(y);
    }
    return x;
}
// END compliant
