// MISRA C++:2023 Rule 4.6.1 (Required)
// Operations on a memory location shall be sequenced appropriately
//
// Example 2: Two modifications of one variable in one expression

// BEGIN violation
int double_increment(int i) {
    return (i++) * (i++);
}
// END violation

// BEGIN compliant
int separate_increments(int i) {
    int first = i;
    ++i;
    int second = i;
    ++i;
    return first * second;
}
// END compliant
