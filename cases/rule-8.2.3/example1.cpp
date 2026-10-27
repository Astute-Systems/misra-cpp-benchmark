// MISRA C++:2023 Rule 8.2.3 (Required)
// A cast shall not remove any const or volatile qualification from the type accessed via a pointer or by reference
//
// Example 1: const_cast removes const from a pointer

// BEGIN violation
char* strip_const(const char* p) {
    return const_cast<char*>(p);
}
// END violation

// BEGIN compliant
const char* keep_const(const char* p) {
    return p;
}
// END compliant
