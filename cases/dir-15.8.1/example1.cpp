// MISRA C++:2023 Directive 15.8.1 (Required)
// User-provided copy assignment operators and move assignment operators shall handle self-assignment
//
// Example 1: Copy assignment without a self-assignment check

// BEGIN violation
struct Buffer {
    int* data = nullptr;
    Buffer& operator=(const Buffer& other) {
        delete[] data;
        data = new int[4];
        for (int i = 0; i < 4; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }
};
// END violation

// BEGIN compliant
struct SafeBuffer {
    int* data = nullptr;
    SafeBuffer& operator=(const SafeBuffer& other) {
        if (this != &other) {
            delete[] data;
            data = new int[4];
            for (int i = 0; i < 4; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};
// END compliant
