#include "MyString.h"
#include <iostream>

int main() {
    // Test the default constructor
    MyString s1;  // default constructor
    MyString s2("Hello");  // parameterized constructor
    MyString s3 = s2;  // copy constructor

    // Test operator==
    std::cout << "s2 == s3: " << (s2 == s3) << std::endl;

    // Test operator!=
    std::cout << "s2 != s3: " << (s2 != s3) << std::endl;

    // Test operator+
    MyString concatenated = s2 + s3;
    std::cout << "Concatenated: " << concatenated << std::endl;

    // Test toLower and toUpper
    MyString lower = s2.toLower();
    MyString upper = s2.toUpper();
    std::cout << "Lowercase: " << lower << std::endl;
    std::cout << "Uppercase: " << upper << std::endl;

    // Test startsWith and endsWith
    std::cout << "s2 starts with 'Hel': " << s2.startsWith("Hel") << std::endl;
    std::cout << "s2 ends with 'lo': " << s2.endsWith("lo") << std::endl;

    // Test reverse
    MyString reversed = s2.reverse();
    std::cout << "Reversed: " << reversed << std::endl;

    // Test clear and isEmpty
    s2.clear();
    std::cout << "s2 is empty: " << s2.isEmpty() << std::endl;

    return 0;
}
