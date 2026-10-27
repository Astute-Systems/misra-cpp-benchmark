// MISRA C++:2023 Rule 22.4.1 (Required)
// The literal value zero shall be the only value assigned to errno
//
// Example 2: Literal non-zero value assigned to errno

#include <cerrno>

// BEGIN violation
void set_errno_literal() {
    errno = 5;
}
// END violation

// BEGIN compliant
int read_errno() {
    return errno;
}
// END compliant
