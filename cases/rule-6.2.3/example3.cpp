// MISRA C++:2023 Rule 6.2.3 (Required)
// The source code used to implement an entity shall appear only once
//
// Example 3: Single definition in a header (compliant counterpart)

#include "example3.h"

// BEGIN compliant
int use_dot_a() {
    return dot2({1, 2}, {3, 4});
}
// END compliant
