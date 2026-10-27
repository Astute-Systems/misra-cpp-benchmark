// MISRA C++:2023 Rule 12.2.1 (Advisory)
// Bit-fields should not be declared
//
// Example 2: Unnamed padding bit-field

// BEGIN violation
struct Padded {
    unsigned int a : 4;
    unsigned int : 4;
};
// END violation

// BEGIN compliant
struct Unpadded {
    unsigned char a;
    unsigned char unused;
};
// END compliant
