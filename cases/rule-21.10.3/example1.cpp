// MISRA C++:2023 Rule 21.10.3 (Required)
// The facilities provided by the standard header file <csignal> shall not be used
//
// Example 1: Signal handler registration

#include <csignal>

void on_interrupt(int);

// BEGIN violation
void install_handler() {
    std::signal(SIGINT, on_interrupt);
}
// END violation

// BEGIN compliant
void no_handler() {
}
// END compliant
