// MISRA C++:2023 Rule 21.6.3 (Required)
// Advanced memory management shall not be used
//
// Example 1: Placement new

#include <new>

struct Widget {
    int v = 0;
};

// BEGIN violation
Widget* place_widget() {
    alignas(Widget) static unsigned char buffer[sizeof(Widget)];
    return new (buffer) Widget();
}
// END violation

// BEGIN compliant
Widget make_widget() {
    Widget w;
    return w;
}
// END compliant
