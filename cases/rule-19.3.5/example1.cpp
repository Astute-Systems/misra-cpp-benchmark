// MISRA C++:2023 Rule 19.3.5 (Required)
// Tokens that look like a preprocessing directive shall not occur within a macro argument
//
// Example 1: Preprocessing directive inside macro arguments

#define IDENTITY(x) x

// BEGIN violation
int directive_in_arguments() {
    return IDENTITY(
#ifdef SOME_FLAG
        1
#else
        2
#endif
    );
}
// END violation

// BEGIN compliant
#ifdef SOME_FLAG
#define SELECTED 1
#else
#define SELECTED 2
#endif

int directive_outside_arguments() {
    return IDENTITY(SELECTED);
}
// END compliant
