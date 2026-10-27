// MISRA C++:2023 Rule 6.0.4 (Required)
// The identifier main shall not be used for a function other than the global function main
//
// Example 2: Member function named main

// BEGIN violation
struct Runner {
    int main();
};
// END violation

// BEGIN compliant
struct Starter {
    int run();
};

int main(int, char**) {
    return 0;
}
// END compliant
