// MISRA C++:2023 Rule 11.6.2 (Mandatory)
// The value of an object must not be read before it has been set
//
// Example 1: Read of an uninitialised local

// BEGIN violation
int read_uninitialised() {
    int x;
    int y = x + 1;
    return y;
}
// END violation

// BEGIN compliant
int read_initialised() {
    int x = 1;
    int y = x + 1;
    return y;
}
// END compliant
