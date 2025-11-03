#include <gtest/gtest.h>
#include "../Costume/Costume.h"

class CostumeTest : public ::testing::Test {
protected:
    void SetUp() override {
        costume.SetExhibitNumberId(12);
        costume.SetExhibitName("Slavic Costume");
        costume.SetExhibitCollection("Historical Costumes");
        costume.SetExhibitFoundationYear(1900);
        costume.SetFabric("Linen");
        costume.SetCostumeType("Dress");
        costume.SetGender("female");
        costume.SetSize(48);
    }

    Costume costume;
};

TEST_F(CostumeTest, Inheritance) {
    EXPECT_EQ(costume.GetExhibitType(), "Costume");
}

TEST_F(CostumeTest, GettersTest) {
    EXPECT_EQ(costume.GetFabric(), "Linen");
    EXPECT_EQ(costume.GetCostumeType(), "Dress");
    EXPECT_EQ(costume.GetGender(), "female");
    EXPECT_EQ(costume.GetSize(), 48);
}

TEST_F(CostumeTest, SettersTest) {
    costume.SetFabric("Cotton");
    costume.SetCostumeType("Jacket");
    costume.SetGender("uni");
    costume.SetSize(52);

    EXPECT_EQ(costume.GetFabric(), "Cotton");
    EXPECT_EQ(costume.GetCostumeType(), "Jacket");
    EXPECT_EQ(costume.GetGender(), "uni");
    EXPECT_EQ(costume.GetSize(), 52);
}

TEST_F(CostumeTest, ConstructorTest) {
    Costume defaultCostume;

    EXPECT_EQ(defaultCostume.GetFabric(), "");
    EXPECT_EQ(defaultCostume.GetCostumeType(), "");
    EXPECT_EQ(defaultCostume.GetGender(), "");
    EXPECT_EQ(defaultCostume.GetSize(), 0);
}

TEST_F(CostumeTest, AsExhibitTest) {
    EXPECT_EQ(costume.GetExhibitNumberId(), 12);
    EXPECT_EQ(costume.GetExhibitName(), "Slavic Costume");
    EXPECT_EQ(costume.GetExhibitCollection(), "Historical Costumes");
    EXPECT_EQ(costume.GetExhibitFoundationYear(), 1900);
}