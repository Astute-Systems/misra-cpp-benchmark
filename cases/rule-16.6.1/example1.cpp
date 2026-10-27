// MISRA C++:2023 Rule 16.6.1 (Advisory)
// Symmetrical operators should only be implemented as non-member functions
//
// Example 1: Symmetric operators implemented as members

// BEGIN violation
struct Money {
    int cents;
    bool operator==(const Money& other) const;
    Money operator+(const Money& other) const;
};
// END violation

// BEGIN compliant
struct Cash {
    int cents;
};

bool operator==(const Cash& a, const Cash& b);
Cash operator+(const Cash& a, const Cash& b);
// END compliant
