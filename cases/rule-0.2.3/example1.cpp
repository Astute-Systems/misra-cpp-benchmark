// MISRA C++:2023 Rule 0.2.3 (Advisory)
// Types with limited visibility should be used at least once
//
// Example 1: Type in an unnamed namespace that is never used

// BEGIN violation
namespace {
struct UnusedType {
    int value;
};
}
// END violation

// BEGIN compliant
namespace {
struct UsedType {
    int value;
};
}

int use_type() {
    UsedType t{1};
    return t.value;
}
// END compliant
