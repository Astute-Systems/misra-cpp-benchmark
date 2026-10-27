// MISRA C++:2023 Rule 19.2.3 (Required)
// The ' or " or \\ characters and the /* or // character sequences shall not occur in a header file name
//
// Example 1: Apostrophe in a header file name

// BEGIN violation
#include "example1_it's.h"
// END violation

int use_apostrophe_header() {
    return apostrophe_header_value;
}
