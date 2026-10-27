// MISRA C++:2023 Rule 6.9.1 (Required)
// The same type aliases shall be used in all declarations of the same entity
//
// Example 1: Redeclaration uses a different spelling of the same type

using Id = unsigned int;

void process(Id id);

// BEGIN violation
void process(unsigned int id) {
    static_cast<void>(id);
}
// END violation

// BEGIN compliant
void handle(Id id);

void handle(Id id) {
    static_cast<void>(id);
}
// END compliant
