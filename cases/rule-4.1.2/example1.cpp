// MISRA C++:2023 Rule 4.1.2 (Advisory)
// Deprecated features should not be used
//
// Example 1: Dynamic exception specification

// BEGIN violation
void legacy_spec() throw();
// END violation

// BEGIN compliant
void modern_spec() noexcept;
// END compliant
