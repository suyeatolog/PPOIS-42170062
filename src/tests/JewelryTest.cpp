#include <gtest/gtest.h>
#include "../Jewelry/Jewelry.h"

class JewelryTest : public ::testing::Test {
protected:
    void SetUp() override {
        ring.SetExhibitNumberId(10);
        ring.SetExhibitName("Imperial Gold Ring");
        ring.SetExhibitCollection("Jewelry");
        ring.SetExhibitFoundationYear(1897);
        ring.SetJewelryMaterial("Gold");
        ring.SetJewelryGemstone("Ruby");
        ring.SetJewelryType("Ring");
        ring.SetJewelryWeight(10.0);
    }

    Jewelry ring;
};

TEST_F(JewelryTest, Inheritance) {
    EXPECT_EQ(ring.GetExhibitType(), "Jewelry");
}

TEST_F(JewelryTest, GettersTest) {
    EXPECT_EQ(ring.GetJewelryMaterial(), "Gold");
    EXPECT_EQ(ring.GetJewelryGemstone(), "Ruby");
    EXPECT_EQ(ring.GetJewelryType(), "Ring");
    EXPECT_DOUBLE_EQ(ring.GetJewelryWeight(), 10.0);
}

TEST_F(JewelryTest, SettersTest) {
    ring.SetJewelryMaterial("Silver");
    ring.SetJewelryGemstone("Emerald");
    ring.SetJewelryType("Small Ring");
    ring.SetJewelryWeight(15.0);

    EXPECT_EQ(ring.GetJewelryMaterial(), "Silver");
    EXPECT_EQ(ring.GetJewelryGemstone(), "Emerald");
    EXPECT_EQ(ring.GetJewelryType(), "Small Ring");
    EXPECT_EQ(ring.GetJewelryWeight(), 15.0);
}

TEST_F(JewelryTest, ConstructorTest) {
    Jewelry defaultNecklace;

    EXPECT_EQ(defaultNecklace.GetJewelryMaterial(), "");
    EXPECT_EQ(defaultNecklace.GetJewelryGemstone(), "");
    EXPECT_EQ(defaultNecklace.GetJewelryType(), "");
    EXPECT_EQ(defaultNecklace.GetJewelryWeight(), 0.0);
}

TEST_F(JewelryTest, AsExhibitTest) {
    EXPECT_EQ(ring.GetExhibitNumberId(), 10);
    EXPECT_EQ(ring.GetExhibitName(), "Imperial Gold Ring");
    EXPECT_EQ(ring.GetExhibitCollection(), "Jewelry");
    EXPECT_EQ(ring.GetExhibitFoundationYear(), 1897);
}