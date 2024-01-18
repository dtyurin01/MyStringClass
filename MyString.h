//
// Created by dtyur on 18.01.2024.
//

#ifndef MYSTRINGCLASS_MYSTRING_H
#define MYSTRINGCLASS_MYSTRING_H

#include <ostream>

class MyString {
private:
    char* data;


public:
    // Getters and Setters
    char* getData() const;
    void setData(char* newData);

    // Length
    size_t my_strlen(const char* str) const;

    // Constructors
    MyString();
    MyString(char* str);
    MyString(const MyString& other);

    // Overloaded operators
    bool operator==(const MyString& rhs) const;
    bool operator!=(const MyString& rhs) const;

    bool operator<(const MyString &rhs) const;

    bool operator>(const MyString &rhs) const;

    bool operator<=(const MyString &rhs) const;

    bool operator>=(const MyString &rhs) const;

    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other) const;

    // Print String
    friend std::ostream& operator<<(std::ostream& os, const MyString& string);

    // Upper Lower

    MyString toLower() const;
    MyString toUpper() const;

    // At Function
    char& at(size_t index);
    const char& at(size_t index) const;

    // Check Methods
    bool isEmpty() const;
    bool startsWith(const MyString& prefix) const;
    bool endsWith(const MyString& suffix) const;

    // Reverse Method
    MyString reverse() const;


    // Clear Method

    void clear();
    // Destructor
    virtual ~MyString();
};



#endif //MYSTRINGCLASS_MYSTRING_H
