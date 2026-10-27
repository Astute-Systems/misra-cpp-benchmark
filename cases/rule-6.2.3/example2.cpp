// MISRA C++:2023 Rule 6.2.3 (Required)
// The source code used to implement an entity shall appear only once
//
// Example 2: Identical external function definition copied into two source files

// BEGIN violation
int clamp_byte(int v) {
    if (v < 0) {
        return 0;
    }
    return (v > 255) ? 255 : v;
}
// END violation
