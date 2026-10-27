// MISRA C++:2023 Rule 19.3.3 (Required)
// The argument to a mixed-use macro parameter shall not be subject to further expansion
//
// Example 1: Macro parameter used both with # and without

#include <cstdio>

#define COUNT 5

// BEGIN violation
#define SHOW(v) std::printf("%s=%d\n", #v, v)

void show_count() {
    SHOW(COUNT);
}
// END violation

// BEGIN compliant
#define SHOW_NAME(v) std::printf("%s\n", #v)

void show_count_name() {
    SHOW_NAME(COUNT);
}
// END compliant
