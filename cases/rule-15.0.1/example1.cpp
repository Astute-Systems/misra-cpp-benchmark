// MISRA C++:2023 Rule 15.0.1 (Required)
// Special member functions shall be provided appropriately
//
// Example 1: Destructor declared without the other special member functions

// BEGIN violation
struct Resource {
    Resource() = default;
    ~Resource() {}
    int* p = nullptr;
};
// END violation

// BEGIN compliant
struct CompleteResource {
    CompleteResource() = default;
    ~CompleteResource() = default;
    CompleteResource(const CompleteResource&) = delete;
    CompleteResource& operator=(const CompleteResource&) = delete;
    CompleteResource(CompleteResource&&) = delete;
    CompleteResource& operator=(CompleteResource&&) = delete;
    int* p = nullptr;
};
// END compliant
