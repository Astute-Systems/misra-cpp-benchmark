// MISRA C++:2023 Rule 30.0.1 (Required)
// The C Library input/output functions shall not be used
//
// Example 2: fopen and fclose

#include <cstdio>

// BEGIN violation
void c_file() {
    std::FILE* f = std::fopen("data.txt", "r");
    if (f != nullptr) {
        std::fclose(f);
    }
}
// END violation

// BEGIN compliant
#include <fstream>

void stream_file() {
    std::ifstream f("data.txt");
}
// END compliant
