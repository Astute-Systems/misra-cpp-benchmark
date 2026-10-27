// MISRA C++:2023 Rule 10.4.1 (Required)
// The asm declaration shall not be used
//
// Example 2: Extended asm with a memory clobber

// BEGIN violation
void asm_barrier() {
    asm volatile("" ::: "memory");
}
// END violation

// BEGIN compliant
#include <atomic>

void signal_fence_without_asm() {
    std::atomic_signal_fence(std::memory_order_seq_cst);
}
// END compliant
