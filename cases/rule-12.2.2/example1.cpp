// MISRA C++:2023 Rule 12.2.2 (Required)
// A bit-field shall have an appropriate type
//
// Example 1: Bit-field of plain char type

// BEGIN violation
struct CharField {
    char flag : 2;
};
// END violation

// BEGIN compliant
struct UnsignedCharField {
    unsigned char flag : 2;
};
// END compliant
