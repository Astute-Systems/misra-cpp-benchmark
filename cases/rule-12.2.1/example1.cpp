// MISRA C++:2023 Rule 12.2.1 (Advisory)
// Bit-fields should not be declared
//
// Example 1: Bit-fields in a structure

// BEGIN violation
struct Flags {
    unsigned int enabled : 1;
    unsigned int mode : 3;
};
// END violation

// BEGIN compliant
struct PlainFlags {
    bool enabled;
    unsigned char mode;
};
// END compliant
