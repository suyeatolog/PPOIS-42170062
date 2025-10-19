//
// Created by user on 19.10.2025.
//
#include <gtest/gtest.h>
#include "../CeramicVase/CeramicVase.h"

class CeramicVaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        vase.SetExhibitNumberId(4);
        vase.SetExhibitName("Ming Dynasty Vase");
        vase.SetExhibitCollection("Asian Ceramics");
        vase.SetExhibitFoundationYear(1368);
        vase.SetPattern("Blue Dragon");
        vase.SetFragile(true);
        vase.SetLength(30);
        vase.SetWidth(30);
        vase.SetHeight(45);
    }

    CeramicVase vase;
};

TEST_F(CeramicVaseTest, Inheritance) {
    EXPECT_EQ(vase.GetExhibitType(), "Ceramic Vase");
}

TEST_F(CeramicVaseTest, GettersTest) {
    EXPECT_EQ(vase.GetPattern(), "Blue Dragon");
    EXPECT_TRUE(vase.GetFragile());
    EXPECT_EQ(vase.GetLength(), 30);
    EXPECT_EQ(vase.GetWidth(), 30);
    EXPECT_EQ(vase.GetHeight(), 45);
}

TEST_F(CeramicVaseTest, SettersTest) {
    vase.SetPattern("Floral Pattern");
    vase.SetFragile(false);
    vase.SetLength(25);
    vase.SetWidth(25);
    vase.SetHeight(40);

    EXPECT_EQ(vase.GetPattern(), "Floral Pattern");
    EXPECT_FALSE(vase.GetFragile());
    EXPECT_EQ(vase.GetLength(), 25);
    EXPECT_EQ(vase.GetWidth(), 25);
    EXPECT_EQ(vase.GetHeight(), 40);
}

TEST_F(CeramicVaseTest, ConstructorTest) {
    CeramicVase defaultVase;

    EXPECT_EQ(defaultVase.GetPattern(), "");
    EXPECT_TRUE(defaultVase.GetFragile());
    EXPECT_EQ(defaultVase.GetLength(), 0);
    EXPECT_EQ(defaultVase.GetWidth(), 0);
    EXPECT_EQ(defaultVase.GetHeight(), 0);
}

TEST_F(CeramicVaseTest, AsExhibitTest) {
    EXPECT_EQ(vase.GetExhibitNumberId(), 4);
    EXPECT_EQ(vase.GetExhibitName(), "Ming Dynasty Vase");
    EXPECT_EQ(vase.GetExhibitCollection(), "Asian Ceramics");
    EXPECT_EQ(vase.GetExhibitFoundationYear(), 1368);
}