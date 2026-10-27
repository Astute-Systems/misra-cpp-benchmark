// MISRA C++:2023 Rule 13.3.3 (Required)
// The parameters in all declarations or overrides of a function shall either be unnamed or have identical names
//
// Example 1: Overrider uses a different parameter name

// BEGIN violation
struct Sink {
    virtual ~Sink() = default;
    virtual void write(int count);
};

struct FileSink : Sink {
    void write(int n) override;
};
// END violation

// BEGIN compliant
struct Source2 {
    virtual ~Source2() = default;
    virtual void read(int count);
};

struct FileSource : Source2 {
    void read(int count) override;
};
// END compliant
