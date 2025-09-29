#include <gtest/gtest.h>
#include <fstream>
#include "../Include/ReadFile.h"

class ReadFileTest : public ::testing::Test {
    protected:
    void SetUp() override {
        testFilename = "testDictionary.txt";
        std::ofstream file(testFilename);
        file << "apple=яблоко\n";
        file << "car=машина\n";
        file << "computer=компьютер\n";
        file.close();
    }

    void TearDown() override {
        remove(testFilename.c_str());
    }

    std::string testFilename;
};

TEST_F(ReadFileTest, FileExistence) {
    EXPECT_TRUE(ReadFile::FileExists(testFilename));
    EXPECT_FALSE(ReadFile::FileExists("SomeNonExistentFile.txt"));
}

TEST_F(ReadFileTest, ReadDictionary) {
    auto wordPairs = ReadFile::ReadDictionary(testFilename);

    EXPECT_EQ(wordPairs.size(), 3);
    EXPECT_EQ(wordPairs[0].first, "apple");
    EXPECT_EQ(wordPairs[1].first, "car");
    EXPECT_EQ(wordPairs[2].first, "computer");
    EXPECT_EQ(wordPairs[0].second, "яблоко");
    EXPECT_EQ(wordPairs[1].second, "машина");
    EXPECT_EQ(wordPairs[2].second, "компьютер");
}

TEST_F(ReadFileTest, ReadNonExistentFile) {
    testing::internal::CaptureStdout();
    auto wordPairs = ReadFile::ReadDictionary("NonExistentFile.txt");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(wordPairs.empty());
    EXPECT_TRUE(output.find("does not exist") != std::string::npos || output.find("Error") == std::string::npos);
}

TEST_F(ReadFileTest, ReadEmptyFile) {
    std::string emptyFilename = "empty.txt";
    std::ofstream emptyFile(emptyFilename);
    emptyFile.close();

    auto wordPairs = ReadFile::ReadDictionary(emptyFilename);

    EXPECT_TRUE(wordPairs.empty());

    remove(emptyFilename.c_str());
}

TEST_F(ReadFileTest, ReadFileWithInvalidFormat) {
    std::string invalidFilename = "invalid.txt";
    std::ofstream invalidFile(invalidFilename);
    invalidFile << "invalid_line_without_equals\n";
    invalidFile << "=empty_value\n";
    invalidFile << "empty_key=\n";
    invalidFile << "valid=correct\n";
    invalidFile.close();

    testing::internal::CaptureStdout();
    auto wordPairs = ReadFile::ReadDictionary(invalidFilename);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(wordPairs.size(), 1);
    EXPECT_EQ(wordPairs[0].first, "valid");
    EXPECT_EQ(wordPairs[0].second, "correct");

    remove(invalidFilename.c_str());
}