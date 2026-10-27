// MISRA C++:2023 Rule 6.5.2 (Advisory)
// Internal linkage should be specified appropriately
//
// Example 2: Non-constant variable with internal linkage defined in a header

#include "example2.h"

int read_counters() {
    return static_counter + inline_counter + kLimit;
}
