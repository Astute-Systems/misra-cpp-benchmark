// MISRA C++:2023 Rule 19.2.1 (Required)
// Precautions shall be taken in order to prevent the contents of a header file being included more than once
//
// Example 1: Header without an include guard

#include "example1.h"

int use_unguarded() {
    Unguarded u{1};
    return u.v;
}
