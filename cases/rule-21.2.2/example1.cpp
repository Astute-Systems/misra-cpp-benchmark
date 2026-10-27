// MISRA C++:2023 Rule 21.2.2 (Required)
// The string handling functions from <cstring>, <cstdlib>, <cwchar> and <cinttypes> shall not be used
//
// Example 1: strlen and strcmp

#include <cstring>

// BEGIN violation
std::size_t use_strlen(const char* s) {
    return std::strlen(s);
}

int use_strcmp(const char* a, const char* b) {
    return std::strcmp(a, b);
}
// END violation

// BEGIN compliant
#include <string>

std::size_t use_string_size(const std::string& s) {
    return s.size();
}
// END compliant
