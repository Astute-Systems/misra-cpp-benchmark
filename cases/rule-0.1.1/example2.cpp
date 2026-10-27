// MISRA C++:2023 Rule 0.1.1 (Advisory)
// A write to a local object should be necessary
//
// Example 2: Result stored in a local that is never read

int compute();

// BEGIN violation
void dead_store() {
    int y = 0;
    y = compute();
}
// END violation

// BEGIN compliant
int live_store() {
    int y = compute();
    return y;
}
// END compliant
