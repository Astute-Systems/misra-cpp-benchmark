// MISRA C++:2023 Rule 17.8.1 (Required)
// Function templates shall not be explicitly specialized
//
// Example 1: Explicit specialization of a function template

// BEGIN violation
template <typename T>
int size_of(T) {
    return 1;
}

template <>
int size_of<double>(double) {
    return 8;
}
// END violation

// BEGIN compliant
template <typename T>
int width_of(T) {
    return 1;
}

int width_of(double) {
    return 8;
}
// END compliant
