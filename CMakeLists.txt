cmake_minimum_required(VERSION 3.27)
project(MyStringClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyStringClass main.cpp
        MyString.cpp
        MyString.h
        classUnitTests.h)
