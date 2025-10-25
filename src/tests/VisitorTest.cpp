#include <gtest/gtest.h>
#include "../Visitor/Visitor.h"

class VisitorTest : public ::testing::Test {
protected:
    void SetUp() override {
        testVisitor.SetVisitorName("Gleb");
        testVisitor.SetVisitorAge(22);
        testVisitor.SetVisitorHasTicket(false);
    }

    Visitor testVisitor;
};

TEST_F(VisitorTest, ConstructorTest) {
    Visitor defaultVisitor;
    EXPECT_EQ(defaultVisitor.GetVisitorName(), "");
    EXPECT_EQ(defaultVisitor.GetVisitorAge(), 0);
    EXPECT_FALSE(defaultVisitor.GetVisitorHasTicket());
}

TEST_F(VisitorTest, SettersGettersTest) {
    testVisitor.SetVisitorName("Stas");
    testVisitor.SetVisitorAge(18);
    testVisitor.SetVisitorHasTicket(true);

    EXPECT_EQ(testVisitor.GetVisitorName(), "Stas");
    EXPECT_EQ(testVisitor.GetVisitorAge(), 18);
    EXPECT_TRUE(testVisitor.GetVisitorHasTicket());
}