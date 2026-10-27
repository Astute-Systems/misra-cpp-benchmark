// MISRA C++:2023 Rule 21.10.2 (Required)
// The standard header file <csetjmp> shall not be used
//
// Example 1: setjmp and longjmp

#include <csetjmp>

// BEGIN violation
int jump_back() {
    std::jmp_buf env;
    if (setjmp(env) == 0) {
        std::longjmp(env, 1);
    }
    return 0;
}
// END violation

// BEGIN compliant
int return_normally(bool failed) {
    if (failed) {
        return 1;
    }
    return 0;
}
// END compliant
