// MISRA C++:2023 Rule 18.1.1 (Required)
// An exception object shall not have pointer type
//
// Example 2: Throwing a string literal

// BEGIN violation
void throw_literal() {
    throw "failure";
}
// END violation

// BEGIN compliant
struct Failure {};

void throw_failure() {
    throw Failure{};
}
// END compliant
