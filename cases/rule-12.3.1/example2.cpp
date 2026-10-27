// MISRA C++:2023 Rule 12.3.1 (Required)
// The union keyword shall not be used
//
// Example 2: Anonymous union member

// BEGIN violation
struct Tagged {
    int tag;
    union {
        int i;
        float f;
    };
};
// END violation

// BEGIN compliant
struct TaggedPair {
    int tag;
    int i;
    float f;
};
// END compliant
