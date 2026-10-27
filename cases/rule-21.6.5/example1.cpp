// MISRA C++:2023 Rule 21.6.5 (Required)
// A pointer to an incomplete class type shall not be deleted
//
// Example 1: delete of an incomplete type

struct Opaque;

// BEGIN violation
void delete_opaque(Opaque* p) {
    delete p;
}
// END violation

// BEGIN compliant
struct Complete {};

void delete_complete(Complete* p) {
    delete p;
}
// END compliant
