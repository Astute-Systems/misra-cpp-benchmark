// MISRA C++:2023 Rule 18.4.1 (Required)
// Exception-unfriendly functions shall be noexcept
//
// Example 2: Move operations that are not noexcept

// BEGIN violation
struct Movable {
    Movable() = default;
    Movable(Movable&& other);
    Movable& operator=(Movable&& other);
};
// END violation

// BEGIN compliant
struct NoexceptMovable {
    NoexceptMovable() = default;
    NoexceptMovable(NoexceptMovable&& other) noexcept;
    NoexceptMovable& operator=(NoexceptMovable&& other) noexcept;
};
// END compliant
