// MISRA C++:2023 Rule 6.2.1 (Required)
// The one-definition rule shall not be violated
//
// Example 2: Both translation units use one shared definition (compliant counterpart)

#include "example2.h"

// BEGIN compliant
int shared_id() {
    SharedPacket p{1, 2};
    return p.id;
}
// END compliant
