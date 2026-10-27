// MISRA C++:2023 Rule 8.1.2 (Advisory)
// Variables should be captured explicitly in a non-transient lambda
//
// Example 2: Stored lambda with a default reference capture

// BEGIN violation
int default_reference_capture() {
    int total = 0;
    auto add = [&](int v) { total += v; };
    add(1);
    return total;
}
// END violation

// BEGIN compliant
int explicit_reference_capture() {
    int total = 0;
    auto add = [&total](int v) { total += v; };
    add(1);
    return total;
}
// END compliant
