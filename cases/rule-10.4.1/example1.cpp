// MISRA C++:2023 Rule 10.4.1 (Required)
// The asm declaration shall not be used
//
// Example 1: Basic asm declaration

// BEGIN violation
void asm_nop() {
    asm("");
}
// END violation

// BEGIN compliant
#include <atomic>

void fence_without_asm() {
    std::atomic_thread_fence(std::memory_order_seq_cst);
}
// END compliant
