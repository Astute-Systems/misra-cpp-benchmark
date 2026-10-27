// MISRA C++:2023 Rule 19.6.1 (Advisory)
// The #pragma directive and the _Pragma operator should not be used
//
// Example 1: #pragma directive

// BEGIN violation
#pragma pack(push, 1)
struct PackedPair {
    char a;
    int b;
};
#pragma pack(pop)
// END violation

// BEGIN compliant
struct NaturalPair {
    char a;
    int b;
};
// END compliant
