// MISRA C++:2023 Rule 6.8.3 (Required)
// An assignment operator shall not assign the address of an object with automatic storage duration to an object with a greater lifetime
//
// Example 1: Address of a local stored in a global pointer

int* g_pointer = nullptr;

// BEGIN violation
void leak_address() {
    int local = 0;
    g_pointer = &local;
}
// END violation

// BEGIN compliant
int g_storage = 0;

void keep_address() {
    g_pointer = &g_storage;
}
// END compliant
