// MISRA C++:2023 Rule 9.6.4 (Required)
// A function declared with the [[noreturn]] attribute shall not return
//
// Example 2: Function marked noreturn returns explicitly

// BEGIN violation
[[noreturn]] void returns_explicitly() {
    return;
}
// END violation

// BEGIN compliant
[[noreturn]] void loops_forever() {
    for (;;) {
    }
}
// END compliant
