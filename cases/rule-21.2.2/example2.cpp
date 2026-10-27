// MISRA C++:2023 Rule 21.2.2 (Required)
// The string handling functions from <cstring>, <cstdlib>, <cwchar> and <cinttypes> shall not be used
//
// Example 2: strcpy and strcat

#include <cstring>

// BEGIN violation
void use_strcpy(char* dst, const char* src) {
    std::strcpy(dst, src);
    std::strcat(dst, src);
}
// END violation

// BEGIN compliant
#include <string>

std::string use_string_concat(const std::string& a, const std::string& b) {
    return a + b;
}
// END compliant
