// MISRA C++:2023 Rule 5.13.3 (Required)
// Octal constants shall not be used
//
// Example 2: Octal literals in an initializer list

// BEGIN violation
int octal_table[] = {010, 011, 012};
// END violation

// BEGIN compliant
int decimal_table[] = {8, 9, 10};
int zero_is_fine = 0;
// END compliant
