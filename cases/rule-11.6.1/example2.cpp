// MISRA C++:2023 Rule 11.6.1 (Advisory)
// All variables should be initialized
//
// Example 2: Counter declared without an initializer

// BEGIN violation
int uninitialised_counter(int n) {
    int count;
    count = 0;
    for (int i = 0; i < n; ++i) {
        ++count;
    }
    return count;
}
// END violation

// BEGIN compliant
int initialised_counter(int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        ++count;
    }
    return count;
}
// END compliant
