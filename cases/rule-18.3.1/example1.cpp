// MISRA C++:2023 Rule 18.3.1 (Advisory)
// There should be at least one exception handler to catch all otherwise unhandled exceptions
//
// Example 1: main without a catch-all handler

void do_work();

// BEGIN violation
int main() {
    do_work();
    return 0;
}
// END violation
