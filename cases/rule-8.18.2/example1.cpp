// MISRA C++:2023 Rule 8.18.2 (Advisory)
// The result of an assignment operator should not be used
//
// Example 1: Assignment used as a condition

int next_value();

// BEGIN violation
int assignment_in_condition() {
    int x = 0;
    if ((x = next_value())) {
        return x;
    }
    return 0;
}
// END violation

// BEGIN compliant
int assignment_before_condition() {
    int x = next_value();
    if (x != 0) {
        return x;
    }
    return 0;
}
// END compliant
