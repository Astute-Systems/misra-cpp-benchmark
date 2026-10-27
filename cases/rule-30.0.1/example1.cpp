// MISRA C++:2023 Rule 30.0.1 (Required)
// The C Library input/output functions shall not be used
//
// Example 1: printf

#include <cstdio>

// BEGIN violation
void c_print() {
    std::printf("hello\n");
}
// END violation

// BEGIN compliant
#include <iostream>

void stream_print() {
    std::cout << "hello\n";
}
// END compliant
