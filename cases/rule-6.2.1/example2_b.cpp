#include "example2.h"

// BEGIN compliant
int shared_length() {
    SharedPacket p{1, 2};
    return p.length;
}
// END compliant
