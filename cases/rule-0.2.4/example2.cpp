// MISRA C++:2023 Rule 0.2.4 (Advisory)
// Functions with limited visibility should be used at least once
//
// Example 2: Function in an unnamed namespace that is never called

// BEGIN violation
namespace {
int hidden_unused(int v) {
    return v * 2;
}
}
// END violation

// BEGIN compliant
namespace {
int hidden_used(int v) {
    return v * 2;
}
}

int calls_hidden() {
    return hidden_used(2);
}
// END compliant
