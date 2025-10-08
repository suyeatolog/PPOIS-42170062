cmake_minimum_required(VERSION 4.0)
project(labwork1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_executable(dictionary lab1Dictionary/Source/main.cpp
        lab1Dictionary/Include/Menu.h
        lab1Dictionary/Source/DictionaryNode.cpp
        lab1Dictionary/Source/Dictionary.cpp
        lab1Dictionary/Source/Menu.cpp
        lab1Dictionary/Include/Dictionary.h
        lab1Dictionary/Include/DictionaryNode.h
        lab1Dictionary/Include/ReadFile.h
        lab1Dictionary/Source/ReadFile.cpp
)

add_executable(polynomial
        lab1Polynomial/Include/Polynomial.h
        lab1Polynomial/Source/Polynomial.cpp
        lab1Polynomial/Source/Polynomial_main.cpp
        lab1Polynomial/Include/PolynomialMenu.h
        lab1Polynomial/Source/PolynomialMenu.cpp
)

add_executable(tests
        lab1Dictionary/Include/DictionaryNode.h
        lab1Dictionary/Include/Dictionary.h
        lab1Dictionary/Include/Menu.h
        lab1Dictionary/Include/ReadFile.h
        lab1Dictionary/Source/DictionaryNode.cpp
        lab1Dictionary/Source/Dictionary.cpp
        lab1Dictionary/Source/Menu.cpp
        lab1Dictionary/Source/ReadFile.cpp
        lab1Dictionary/tests/DictionaryNodeTests.cpp
        lab1Dictionary/tests/test_main.cpp
        lab1Dictionary/tests/DictionaryTests.cpp
        lab1Dictionary/tests/ReadFiles.cpp
        lab1Polynomial/Include/Polynomial.h
        lab1Polynomial/Include/PolynomialMenu.h
        lab1Polynomial/Source/Polynomial.cpp
        lab1Polynomial/Source/PolynomialMenu.cpp
        lab1Dictionary/tests/PolynomialTest.cpp
)
target_link_libraries(tests gtest)