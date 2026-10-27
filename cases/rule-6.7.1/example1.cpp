// MISRA C++:2023 Rule 6.7.1 (Required)
// Local variables shall not have static or thread storage duration
//
// Example 1: Function-local static variable

// BEGIN violation
int next_id() {
    static int counter = 0;
    return ++counter;
}
// END violation

// BEGIN compliant
int next_id_from(int previous) {
    return previous + 1;
}
// END compliant
