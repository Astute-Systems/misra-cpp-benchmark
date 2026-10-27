// MISRA C++:2023 Rule 18.3.3 (Required)
// Handlers for a function-try-block of a constructor or destructor shall not refer to non-static members from their class or its bases
//
// Example 1: Constructor handler that touches a member

// BEGIN violation
struct Member {
    int v;
    Member() try : v(0) {
    } catch (...) {
        v = 1;
    }
};
// END violation

// BEGIN compliant
struct SafeMember {
    int v;
    SafeMember() try : v(0) {
    } catch (...) {
        throw;
    }
};
// END compliant
