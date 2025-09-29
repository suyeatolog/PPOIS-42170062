#include <gtest/gtest.h>
#include "../Include/DictionaryNode.h"

TEST(DictionaryNodeTest, ConstructorAndGetters) {
    DictionaryNode node("apple", "яблоко");

    EXPECT_EQ(node.GetEnWord(), "apple");
    EXPECT_EQ(node.GetTranslation(), "яблоко");
    EXPECT_EQ(node.GetLeft(), nullptr);
    EXPECT_EQ(node.GetRight(), nullptr);
}

TEST(DictionaryNodeTest, Setters) {
    DictionaryNode node("apple", "яблоко");

    node.SetEnWord("car");
    node.SetTranslation("машина");

    EXPECT_EQ(node.GetEnWord(), "car");
    EXPECT_EQ(node.GetTranslation(), "машина");

    DictionaryNode* leftnode = new DictionaryNode("apple","яблоко");
    DictionaryNode* rightnode = new DictionaryNode("computer","компьютер");

    node.SetLeft(leftnode);
    node.SetRight(rightnode);

    EXPECT_EQ(node.GetLeft(), leftnode);
    EXPECT_EQ(node.GetRight(), rightnode);

    delete leftnode;
    delete rightnode;
}

TEST(DictionaryNodeTest, PrintNodeTest) {
    DictionaryNode node("apple", "яблоко");

    testing::internal::CaptureStdout();
    node.PrintNode();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());
}