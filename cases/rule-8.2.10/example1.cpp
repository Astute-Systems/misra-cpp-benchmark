// MISRA C++:2023 Rule 8.2.10 (Required)
// Functions shall not call themselves, either directly or indirectly
//
// Example 1: Direct recursion

// BEGIN violation
int factorial_recursive(int n) {
    return (n <= 1) ? 1 : n * factorial_recursive(n - 1);
}
// END violation

// BEGIN compliant
int factorial_iterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
// END compliant
