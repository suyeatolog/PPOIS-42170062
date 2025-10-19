#include <gtest/gtest.h>
#include "../HandmadeTowel/HandmadeTowel.h"

class HandmadeTowelTest : public ::testing::Test {
protected:
    void SetUp() override {
        towel.SetExhibitNumberId(8);
        towel.SetExhibitName("Traditional Slavic Towel");
        towel.SetExhibitCollection("Folk Art");
        towel.SetExhibitFoundationYear(1890);
        towel.SetFabricType("Linen");
        towel.SetEmbroideryStyle("Cross-stitch");
        towel.SetColorScheme("Red-white");
        towel.SetLength(150);
        towel.SetWidth(50);
        towel.SetIsDecorative(true);
    }

    HandmadeTowel towel;
};

TEST_F(HandmadeTowelTest, Inheritance) {
    EXPECT_EQ(towel.GetExhibitType(), "Handmade Towel");
}

TEST_F(HandmadeTowelTest, GettersTest) {
    EXPECT_EQ(towel.GetFabricType(), "Linen");
    EXPECT_EQ(towel.GetEmbroideryStyle(), "Cross-stitch");
    EXPECT_EQ(towel.GetColorScheme(), "Red-white");
    EXPECT_EQ(towel.GetLength(), 150);
    EXPECT_EQ(towel.GetWidth(), 50);
    EXPECT_TRUE(towel.GetIsDecorative());
}

TEST_F(HandmadeTowelTest, SettersTest) {
    towel.SetFabricType("Cotton");
    towel.SetEmbroideryStyle("Satin stitch");
    towel.SetColorScheme("Blue-gold");
    towel.SetLength(120);
    towel.SetWidth(40);
    towel.SetIsDecorative(false);

    EXPECT_EQ(towel.GetFabricType(), "Cotton");
    EXPECT_EQ(towel.GetEmbroideryStyle(), "Satin stitch");
    EXPECT_EQ(towel.GetColorScheme(), "Blue-gold");
    EXPECT_EQ(towel.GetLength(), 120);
    EXPECT_EQ(towel.GetWidth(), 40);
    EXPECT_FALSE(towel.GetIsDecorative());
}

TEST_F(HandmadeTowelTest, ConstructorTest) {
    HandmadeTowel defaultTowel;

    EXPECT_EQ(defaultTowel.GetFabricType(), "");
    EXPECT_EQ(defaultTowel.GetEmbroideryStyle(), "");
    EXPECT_EQ(defaultTowel.GetColorScheme(), "");
    EXPECT_EQ(defaultTowel.GetLength(), 0);
    EXPECT_EQ(defaultTowel.GetWidth(), 0);
    EXPECT_TRUE(defaultTowel.GetIsDecorative());
}

TEST_F(HandmadeTowelTest, AsExhibitTest) {
    EXPECT_EQ(towel.GetExhibitNumberId(), 8);
    EXPECT_EQ(towel.GetExhibitName(), "Traditional Slavic Towel");
    EXPECT_EQ(towel.GetExhibitCollection(), "Folk Art");
    EXPECT_EQ(towel.GetExhibitFoundationYear(), 1890);
}