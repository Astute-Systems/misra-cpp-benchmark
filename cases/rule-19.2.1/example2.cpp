// MISRA C++:2023 Rule 19.2.1 (Required)
// Precautions shall be taken in order to prevent the contents of a header file being included more than once
//
// Example 2: Header with an include guard (compliant counterpart)

#include "example2.h"

int use_guarded() {
    Guarded g{1};
    return g.v;
}
