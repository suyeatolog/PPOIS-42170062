#include <gtest/gtest.h>
#include "../Include/Dictionary.h"

class DictionaryTest : public ::testing::Test {
    protected:
    void SetUp() override {
        dict = new Dictionary();
    }

    void TearDown() override {
        delete dict;
    }

    Dictionary* dict;
};

TEST_F(DictionaryTest, AddWordToDictionary) {
    *dict += std::make_pair("apple", "ябоко");

    EXPECT_FALSE(dict->IsEmpty());
    EXPECT_EQ(dict->GetWordCount(), 1);
    EXPECT_TRUE(dict->WordExists("apple"));
}

TEST_F(DictionaryTest, AddMultipleWordsToDictionary) {
    *dict += std::make_pair("apple", "яблоко");
    *dict += std::make_pair("car", "машина");
    *dict += std::make_pair("computer", "компьютер");

    EXPECT_FALSE(dict->IsEmpty());
    EXPECT_EQ(dict->GetWordCount(), 3);
    EXPECT_TRUE(dict->WordExists("apple"));
    EXPECT_TRUE(dict->WordExists("car"));
    EXPECT_TRUE(dict->WordExists("computer"));
}

TEST_F(DictionaryTest, AddDuplicateToDictionary) {
    *dict += std::make_pair("apple", "яблоко");
    *dict += std::make_pair("apple", "неяблоко");

    EXPECT_EQ(dict->GetWordCount(), 1);
    EXPECT_EQ((*dict)["apple"], "неяблоко");
}

TEST_F(DictionaryTest, DeleteWordFromDictionary) {
    *dict += std::make_pair("apple", "яблоко");
    *dict += std::make_pair("car", "машина");
    *dict -= "apple";

    EXPECT_EQ(dict->GetWordCount(), 1);
    EXPECT_FALSE(dict->WordExists("apple"));
    EXPECT_TRUE(dict->WordExists("car"));
}

TEST_F(DictionaryTest, DeleteMultipleWordsFromDictionary) {
    *dict += std::make_pair("apple", "яблоко");
    *dict += std::make_pair("car", "машина");
    *dict += std::make_pair("computer", "компьютер");
    *dict += std::make_pair("oak", "дуб");

    *dict -= "apple";
    *dict -= "car";
    *dict -= "computer";

    EXPECT_EQ(dict->GetWordCount(), 1);
    EXPECT_TRUE(dict->WordExists("oak"));
    EXPECT_FALSE(dict->WordExists("apple"));
    EXPECT_FALSE(dict->WordExists("car"));
    EXPECT_FALSE(dict->WordExists("computer"));
}

TEST_F(DictionaryTest, DeleteNonExistentWordFromDictionary) {
    *dict += std::make_pair("apple", "яблоко");

    *dict -= "car";

    EXPECT_EQ(dict->GetWordCount(), 1);
    EXPECT_TRUE(dict->WordExists("apple"));
}

TEST_F(DictionaryTest, SearchWordTranslationInDictionary) {
    *dict += std::make_pair("apple", "яблоко");
    *dict += std::make_pair("car", "машина");

    EXPECT_EQ((*dict)["apple"], "яблоко");
    EXPECT_EQ((*dict)["car"], "машина");
}

TEST_F(DictionaryTest, SearchNonExistentWordInDictionary) {
    std::string result = (*dict)["apple"];
    EXPECT_EQ(result, "The word You are looking for seems to be missing in this dictionary.");
}

TEST_F(DictionaryTest, ChangeTranslationOfTheWordInDictionary) {
    *dict += std::make_pair("apple", "яблоко");

    dict->ChangeTranslation("apple","яблочко");

    EXPECT_EQ((*dict)["apple"], "яблочко");
}

TEST_F(DictionaryTest, ChangeTranslationOfNonExistentTheWordInDictionary) {
    testing::internal::CaptureStdout();
    dict->ChangeTranslation("apple", "яблоко");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("missing") != std::string::npos);
}

TEST_F(DictionaryTest, ClearDictionary) {
    *dict += std::make_pair("apple", "яблоко");
    *dict += std::make_pair("car", "машина");

    dict->ClearDictionaryForFile();

    EXPECT_TRUE(dict->IsEmpty());
    EXPECT_EQ(dict->GetWordCount(), 0);
}

TEST_F(DictionaryTest, PrintDictionary) {
    *dict += std::make_pair("apple", "яблоко");

    testing::internal::CaptureStdout();
    dict->PrintDictionary();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(output.find("apple") != std::string::npos);
    EXPECT_TRUE(output.find("яблоко") != std::string::npos);
}

TEST_F(DictionaryTest, PrintEmptyDictionary) {
    testing::internal::CaptureStdout();
    dict->PrintDictionary();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("empty") != std::string::npos);
}

TEST_F(DictionaryTest, DeleteWordWith2Branches) {
    *dict += std::make_pair("dog", "собака");
    *dict += std::make_pair("banana", "банан");
    *dict += std::make_pair("apple", "яблоко");
    *dict += std::make_pair("cat", "кот");
    *dict += std::make_pair("elephant", "слон");

    int initialCount = dict->GetWordCount();

    *dict -= "banana";

    EXPECT_FALSE(dict->WordExists("banana"));
    EXPECT_EQ(dict->GetWordCount(), initialCount-1);

    EXPECT_TRUE(dict->WordExists("apple"));
    EXPECT_TRUE(dict->WordExists("cat"));
    EXPECT_TRUE(dict->WordExists("dog"));
    EXPECT_TRUE(dict->WordExists("elephant"));

    EXPECT_EQ((*dict)["apple"], "яблоко");
    EXPECT_EQ((*dict)["cat"], "кот");
}