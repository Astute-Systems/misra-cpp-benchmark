// MISRA C++:2023 Rule 6.2.2 (Required)
// All declarations of a variable or function shall have the same type
//
// Example 2: Function declared with two different return types

// BEGIN violation
extern "C" int sensor_read() {
    return 1;
}
// END violation
