// MISRA C++:2023 Rule 18.3.2 (Required)
// An exception of class type shall be caught by const reference or reference
//
// Example 2: Handler for a user class by value

struct AppError {
    int code;
};

void might_fail();

// BEGIN violation
int catch_user_by_value() {
    try {
        might_fail();
    } catch (AppError err) {
        return err.code;
    }
    return 0;
}
// END violation

// BEGIN compliant
int catch_user_by_reference() {
    try {
        might_fail();
    } catch (const AppError& err) {
        return err.code;
    }
    return 0;
}
// END compliant
