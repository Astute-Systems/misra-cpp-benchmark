// MISRA C++:2023 Rule 18.3.1 (Advisory)
// There should be at least one exception handler to catch all otherwise unhandled exceptions
//
// Example 2: main that catches everything (compliant counterpart)

void do_work();

// BEGIN compliant
int main() {
    try {
        do_work();
        return 0;
    } catch (...) {
        return 1;
    }
}
// END compliant
