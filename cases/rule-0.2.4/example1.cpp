// MISRA C++:2023 Rule 0.2.4 (Advisory)
// Functions with limited visibility should be used at least once
//
// Example 1: Static function that is never called

// BEGIN violation
static int never_called(int v) {
    return v + 1;
}
// END violation

// BEGIN compliant
static int called(int v) {
    return v + 1;
}

int caller() {
    return called(1);
}
// END compliant
