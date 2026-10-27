// MISRA C++:2023 Rule 6.7.1 (Required)
// Local variables shall not have static or thread storage duration
//
// Example 2: Function-local thread storage

// BEGIN violation
int per_thread() {
    thread_local int value = 0;
    return ++value;
}
// END violation

// BEGIN compliant
int per_call() {
    int value = 0;
    return ++value;
}
// END compliant
