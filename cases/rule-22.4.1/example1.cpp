// MISRA C++:2023 Rule 22.4.1 (Required)
// The literal value zero shall be the only value assigned to errno
//
// Example 1: Non-zero value assigned to errno

#include <cerrno>

// BEGIN violation
void set_errno() {
    errno = EINVAL;
}
// END violation

// BEGIN compliant
void clear_errno() {
    errno = 0;
}
// END compliant
