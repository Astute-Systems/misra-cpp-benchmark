// MISRA C++:2023 Rule 19.6.1 (Advisory)
// The #pragma directive and the _Pragma operator should not be used
//
// Example 2: _Pragma operator

// BEGIN violation
_Pragma("pack(push, 2)")
struct PackedWords {
    char a;
    int b;
};
_Pragma("pack(pop)")
// END violation

// BEGIN compliant
struct UnpackedWords {
    char a;
    int b;
};
// END compliant
