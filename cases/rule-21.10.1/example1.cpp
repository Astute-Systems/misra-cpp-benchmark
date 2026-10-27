// MISRA C++:2023 Rule 21.10.1 (Required)
// The features of <cstdarg> shall not be used
//
// Example 1: va_list in a variadic function

#include <cstdarg>

// BEGIN violation
int sum_variadic(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; ++i) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}
// END violation

// BEGIN compliant
template <typename... Ts>
int count_arguments(Ts... values) {
    return static_cast<int>(sizeof...(values));
}
// END compliant
