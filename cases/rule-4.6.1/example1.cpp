// MISRA C++:2023 Rule 4.6.1 (Required)
// Operations on a memory location shall be sequenced appropriately
//
// Example 1: Variable read and modified in the same expression

// BEGIN violation
int read_and_increment(int i) {
    return i + i++;
}
// END violation

// BEGIN compliant
int increment_then_read(int i) {
    int old = i;
    ++i;
    return old + i;
}
// END compliant
