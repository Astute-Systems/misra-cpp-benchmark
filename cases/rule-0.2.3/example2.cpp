// MISRA C++:2023 Rule 0.2.3 (Advisory)
// Types with limited visibility should be used at least once
//
// Example 2: Local type alias that is never used

// BEGIN violation
void unused_alias() {
    using Counter = unsigned int;
}
// END violation

// BEGIN compliant
unsigned int used_alias() {
    using Counter = unsigned int;
    Counter c = 1U;
    return c;
}
// END compliant
