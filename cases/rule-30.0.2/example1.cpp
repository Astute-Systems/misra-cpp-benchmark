// MISRA C++:2023 Rule 30.0.2 (Required)
// Reads and writes on the same file stream shall be separated by a positioning operation
//
// Example 1: Write followed by read on the same stream

#include <fstream>

// BEGIN violation
int write_then_read() {
    std::fstream f("data.txt", std::ios::in | std::ios::out);
    int v = 0;
    f << 1;
    f >> v;
    return v;
}
// END violation

// BEGIN compliant
int write_seek_read() {
    std::fstream f("data.txt", std::ios::in | std::ios::out);
    int v = 0;
    f << 1;
    f.seekg(0);
    f >> v;
    return v;
}
// END compliant
