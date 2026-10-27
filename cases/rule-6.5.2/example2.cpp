// MISRA C++:2023 Rule 6.5.2 (Advisory)
// Internal linkage should be specified appropriately
//
// Example 2: Source-file-only function left with external linkage

// BEGIN violation
int used_only_here(int v) {
    return v + 1;
}

int caller_of_external() {
    return used_only_here(1);
}
// END violation

// BEGIN compliant
static int used_only_here_internal(int v) {
    return v + 1;
}

int caller_of_internal() {
    return used_only_here_internal(1);
}
// END compliant
