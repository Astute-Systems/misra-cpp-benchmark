// MISRA C++:2023 Rule 19.2.3 (Required)
// The ' or " or \\ characters and the /* or // character sequences shall not occur in a header file name
//
// Example 3: Ordinary header file name (compliant counterpart)

// BEGIN compliant
#include "example3_plain.h"
// END compliant

int use_plain_header() {
    return plain_header_value;
}
