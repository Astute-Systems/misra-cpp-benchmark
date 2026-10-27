// MISRA C++:2023 Rule 8.2.4 (Required)
// Casts shall not be performed between a pointer to function and any other type
//
// Example 1: Function pointer converted to void*

void target();

// BEGIN violation
void* function_to_object_pointer() {
    return reinterpret_cast<void*>(&target);
}
// END violation

// BEGIN compliant
void (*function_pointer_unchanged())() {
    return &target;
}
// END compliant
