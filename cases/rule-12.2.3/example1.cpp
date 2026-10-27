// MISRA C++:2023 Rule 12.2.3 (Required)
// A named bit-field with signed integer type shall not have a length of one bit
//
// Example 1: Signed one-bit field

// BEGIN violation
struct SignedBit {
    signed int bit : 1;
};
// END violation

// BEGIN compliant
struct UnsignedBit {
    unsigned int bit : 1;
};
// END compliant
