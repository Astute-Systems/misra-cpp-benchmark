// MISRA C++:2023 Rule 9.6.2 (Required)
// A goto statement shall reference a label in a surrounding block
//
// Example 1: goto into a sibling block

// BEGIN violation
int goto_into_block(int x) {
    if (x > 0) {
        goto inner;
    }
    {
    inner:
        ++x;
    }
    return x;
}
// END violation

// BEGIN compliant
int goto_to_enclosing_block(int x) {
    if (x > 0) {
        goto done;
    }
    ++x;
done:
    return x;
}
// END compliant
