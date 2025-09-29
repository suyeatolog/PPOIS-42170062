#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char **argv) {
    std::cout << "=== Running Dictionary Tests ===" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);

    int result = RUN_ALL_TESTS();

    std::cout << "=== Tests Finished ===" << std::endl;
    return result;
}