// MISRA C++:2023 Rule 4.1.3 (Required)
// There shall be no occurrence of undefined or critical unspecified behaviour
//
// Example 2: Constant index beyond the end of an array

// BEGIN violation
int out_of_bounds() {
    int values[3] = {1, 2, 3};
    return values[5];
}
// END violation

// BEGIN compliant
int in_bounds() {
    int values[3] = {1, 2, 3};
    return values[2];
}
// END compliant
