// MISRA C++:2023 Rule 6.2.4 (Required)
// A header file shall not contain definitions of functions or objects that are non-inline and have external linkage
//
// Example 2: Header declares and defines inline (compliant counterpart)

#include "example2.h"

// BEGIN compliant
int counter_in_source = 0;
int use_header2() {
    return twice2(counter_in_source);
}
// END compliant
