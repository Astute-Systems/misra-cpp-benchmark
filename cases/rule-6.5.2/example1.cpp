// MISRA C++:2023 Rule 6.5.2 (Advisory)
// Internal linkage should be specified appropriately
//
// Example 1: Function with internal linkage defined in a header

#include "example1.h"

int use_inline_helper() {
    return inline_helper(1);
}
