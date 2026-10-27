// MISRA C++:2023 Rule 6.4.3 (Required)
// An identifier that is present in a dependent base shall not be resolved by unqualified lookup
//
// Example 2: Unqualified use of a dependent base data member

int value = 0;

template <typename T>
struct DataBase {
    int value;
};

// BEGIN violation
template <typename T>
struct DataHidden : DataBase<T> {
    int get() {
        return value;
    }
};
// END violation

// BEGIN compliant
template <typename T>
struct DataQualified : DataBase<T> {
    int get() {
        return this->value;
    }
};
// END compliant
