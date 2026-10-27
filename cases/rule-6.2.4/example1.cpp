// MISRA C++:2023 Rule 6.2.4 (Required)
// A header file shall not contain definitions of functions or objects that are non-inline and have external linkage
//
// Example 1: Header defines a non-inline function and an object

#include "example1.h"

int use_header() {
    return twice(counter_in_header);
}
