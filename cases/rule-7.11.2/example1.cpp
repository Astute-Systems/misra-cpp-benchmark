// MISRA C++:2023 Rule 7.11.2 (Required)
// An array passed as a function argument shall not decay to a pointer
//
// Example 1: Array decays to a pointer when passed

int sum_pointer(const int* values);

// BEGIN violation
int decays() {
    int a[4] = {1, 2, 3, 4};
    return sum_pointer(a);
}
// END violation

// BEGIN compliant
template <unsigned long N>
int sum_reference(const int (&values)[N]) {
    return values[0];
}

int does_not_decay() {
    int a[4] = {1, 2, 3, 4};
    return sum_reference(a);
}
// END compliant
