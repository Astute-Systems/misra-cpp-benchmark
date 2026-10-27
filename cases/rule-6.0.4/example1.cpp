// MISRA C++:2023 Rule 6.0.4 (Required)
// The identifier main shall not be used for a function other than the global function main
//
// Example 1: Function named main inside a namespace

// BEGIN violation
namespace tools {
int main() {
    return 0;
}
}  // namespace tools
// END violation

// BEGIN compliant
int main() {
    return 0;
}
// END compliant
