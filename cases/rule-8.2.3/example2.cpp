// MISRA C++:2023 Rule 8.2.3 (Required)
// A cast shall not remove any const or volatile qualification from the type accessed via a pointer or by reference
//
// Example 2: const_cast removes volatile from a reference

// BEGIN violation
int& strip_volatile(volatile int& v) {
    return const_cast<int&>(v);
}
// END violation

// BEGIN compliant
volatile int& keep_volatile(volatile int& v) {
    return v;
}
// END compliant
