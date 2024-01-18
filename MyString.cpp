#include "MyString.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif


// Lower Upper

char customToLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

// Custom implementation of std::toupper
char customToUpper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch;
}

// Getters and Setters
char* MyString::getData() const {
    return data;
}

void MyString::setData(char* newData) {
    // It's better to use a deep copy instead of assigning the pointer directly
    size_t len = my_strlen(newData);
    delete[] data;
    data = new char[len + 1];
    for (size_t i = 0; i <= len; ++i) {
        data[i] = newData[i];
    }
}

// Length
size_t MyString::my_strlen(const char* str) const {
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

// Constructor
MyString::MyString() : data(new char[1]) {
    data[0] = '\0';
}

MyString::MyString(char *str) {
    if (str != nullptr) {
        size_t len = my_strlen(str);
        data = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            data[i] = str[i];
        }
        data[len] = '\0';
    } else {
        data = nullptr;
    }
}

MyString::MyString(const MyString& other) {
    size_t len = my_strlen(other.data);
    data = new char[len + 1];
    for (size_t i = 0; i <= len; ++i) {
        data[i] = other.data[i];
    }
}

// Overloaded operators
bool MyString::operator==(const MyString &rhs) const {
    return data == rhs.data;
}

bool MyString::operator!=(const MyString &rhs) const {
    return !(rhs == *this);
}

bool MyString::operator<(const MyString &rhs) const {
    return data < rhs.data;
}

bool MyString::operator>(const MyString &rhs) const {
    return rhs < *this;
}

bool MyString::operator<=(const MyString &rhs) const {
    return !(rhs < *this);
}

bool MyString::operator>=(const MyString &rhs) const {
    return !(*this < rhs);
}




MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        size_t len = my_strlen(other.data);
        data = new char[len + 1];
        for (size_t i = 0; i <= len; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    MyString result;
    size_t len1 = my_strlen(data);
    size_t len2 = my_strlen(other.data);
    result.data = new char[len1 + len2 + 1];

    for (size_t i = 0; i < len1; ++i) {
        result.data[i] = data[i];
    }
    for (size_t i = 0; i <= len2; ++i) {
        result.data[len1 + i] = other.data[i];
    }
    return result;
}


// ToLower method
MyString MyString::toLower() const {
    MyString result(*this);  // Create a copy of the current object

    for (size_t i = 0; i < my_strlen(result.data); ++i) {
        result.data[i] = customToLower(result.data[i]);
    }

    return result;
}

// ToUpper method
MyString MyString::toUpper() const {
    MyString result(*this);  // Create a copy of the current object

    for (size_t i = 0; i < my_strlen(result.data); ++i) {
        result.data[i] = customToUpper(result.data[i]);
    }

    return result;
}

// at Method

char& MyString::at(size_t index) {
    if (index < my_strlen(data)) {
        return data[index];
    } else {
        std::cerr << "Index out of bounds! Returning the last character.\n";
        return data[my_strlen(data) - 1]; // last symbol
    }
}

const char& MyString::at(size_t index) const {
    if (index < my_strlen(data)) {
        return data[index];
    } else {
        std::cerr << "Index out of bounds! Returning the last character.\n";
        return data[my_strlen(data) - 1];
    }
}
// Check Methods

bool MyString::isEmpty() const {
    return (data == nullptr) || (my_strlen(data) == 0);
}

bool MyString::startsWith(const MyString& prefix) const {
    size_t prefixLen = my_strlen(prefix.data);
    size_t len = my_strlen(data);

    if (len < prefixLen) {
        return false;
    }

    for (size_t i = 0; i < prefixLen; ++i) {
        if (data[i] != prefix.data[i]) {
            return false;
        }
    }

    return true;
}

bool MyString::endsWith(const MyString& suffix) const {
    size_t suffixLen = my_strlen(suffix.data);
    size_t len = my_strlen(data);

    if (len < suffixLen) {
        return false;
    }

    for (size_t i = 0; i < suffixLen; ++i) {
        if (data[len - suffixLen + i] != suffix.data[i]) {
            return false;
        }
    }

    return true;
}
// Reverse Method
MyString MyString::reverse() const {
    MyString result(*this);  // Create a copy of the current object

    size_t len = my_strlen(result.data);

    for (size_t i = 0; i < len / 2; ++i) {
        // Swap characters from the beginning and end of the string
        char temp = result.data[i];
        result.data[i] = result.data[len - i - 1];
        result.data[len - i - 1] = temp;
    }

    return result;
}
// Clear Method
void MyString::clear() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}

// Print String
std::ostream& operator<<(std::ostream& os, const MyString& string) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to bright green
#else
    os << "\033[1;32m"; // ANSI escape code for bold green text
#endif

    os << "data: ";

#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset text color
#else
    os << "\033[0m"; // Reset ANSI escape codes
#endif

    if (string.data != nullptr) {
#ifdef _WIN32
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Set text color to bright blue
#else
        os << "\033[1;34m"; // ANSI escape code for bold blue text
#endif

        os << string.data;

#ifdef _WIN32
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset text color
#else
        os << "\033[0m"; // Reset ANSI escape codes
#endif
    } else {
        os << "nullptr";
    }
    return os;
}

// Destructor
MyString::~MyString() {
//    std::cout << "deleted: " << data << std::endl;
    delete[] data;
}

