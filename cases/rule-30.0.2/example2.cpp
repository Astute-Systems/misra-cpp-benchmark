// MISRA C++:2023 Rule 30.0.2 (Required)
// Reads and writes on the same file stream shall be separated by a positioning operation
//
// Example 2: Read followed by write on the same stream

#include <fstream>

// BEGIN violation
void read_then_write() {
    std::fstream f("data.txt", std::ios::in | std::ios::out);
    int v = 0;
    f >> v;
    f << v;
}
// END violation

// BEGIN compliant
void read_seek_write() {
    std::fstream f("data.txt", std::ios::in | std::ios::out);
    int v = 0;
    f >> v;
    f.seekp(0);
    f << v;
}
// END compliant
