// MISRA C++:2023 Rule 10.2.3 (Required)
// The numeric value of an unscoped enumeration with no fixed underlying type shall not be used
//
// Example 2: Unscoped enumeration used as an array index

// BEGIN violation
enum Slot { First, Second };

int slot_lookup() {
    static const int table[2] = {10, 20};
    return table[Second];
}
// END violation

// BEGIN compliant
enum class Index : int { First, Second };

int index_lookup() {
    static const int table[2] = {10, 20};
    return table[static_cast<int>(Index::Second)];
}
// END compliant
