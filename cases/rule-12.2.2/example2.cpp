// MISRA C++:2023 Rule 12.2.2 (Required)
// A bit-field shall have an appropriate type
//
// Example 2: Bit-field of an unfixed enumeration type

// BEGIN violation
enum Kind { Small, Large };

struct EnumField {
    Kind kind : 2;
};
// END violation

// BEGIN compliant
enum class FixedKind : unsigned char { Small, Large };

struct FixedEnumField {
    FixedKind kind : 2;
};
// END compliant
