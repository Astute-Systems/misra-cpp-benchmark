// MISRA C++:2023 Rule 19.2.3 (Required)
// The ' or " or \\ characters and the /* or // character sequences shall not occur in a header file name
//
// Example 2: Double slash in a header file name

// BEGIN violation
#include "inc//example2_inc.h"
// END violation

int use_double_slash_header() {
    return double_slash_value;
}
