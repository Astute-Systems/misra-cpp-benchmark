// MISRA C++:2023 Rule 10.3.1 (Advisory)
// There should be no unnamed namespaces in header files
//
// Example 1: Unnamed namespace in a header

#include "example1.h"

int use_hidden() {
    return named_in_header::value + 1;
}
