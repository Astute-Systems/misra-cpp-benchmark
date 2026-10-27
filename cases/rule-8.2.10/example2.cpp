// MISRA C++:2023 Rule 8.2.10 (Required)
// Functions shall not call themselves, either directly or indirectly
//
// Example 2: Mutual recursion

int is_even(int n);

// BEGIN violation
int is_odd(int n) {
    return (n == 0) ? 0 : is_even(n - 1);
}

int is_even(int n) {
    return (n == 0) ? 1 : is_odd(n - 1);
}
// END violation

// BEGIN compliant
int is_even_loop(int n) {
    return (n % 2 == 0) ? 1 : 0;
}
// END compliant
