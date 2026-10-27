// MISRA C++:2023 Rule 9.6.4 (Required)
// A function declared with the [[noreturn]] attribute shall not return
//
// Example 1: Function marked noreturn can fall off the end

// BEGIN violation
[[noreturn]] void maybe_returns(int x) {
    if (x > 0) {
        throw 1;
    }
}
// END violation

// BEGIN compliant
[[noreturn]] void always_throws(int x) {
    throw x;
}
// END compliant
