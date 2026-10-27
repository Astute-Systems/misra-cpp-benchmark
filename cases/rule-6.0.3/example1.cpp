// MISRA C++:2023 Rule 6.0.3 (Advisory)
// The only declarations in the global namespace should be main, namespace declarations and extern "C" declarations
//
// Example 1: Function and variable declared in the global namespace

// BEGIN violation
int global_value = 0;

void global_helper() {}
// END violation

// BEGIN compliant
namespace app {
int scoped_value = 0;

void scoped_helper() {}
}  // namespace app

extern "C" void c_linkage_function() {}
// END compliant
