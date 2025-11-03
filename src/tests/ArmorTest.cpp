#include <gtest/gtest.h>
#include "../Armor/Armor.h"

class ArmorTest : public ::testing::Test {
protected:
    void SetUp() override {
        ironArmor.SetExhibitNumberId(11);
        ironArmor.SetExhibitName("Iron Armor Set");
        ironArmor.SetExhibitCollection("Medieval Armors");
        ironArmor.SetExhibitFoundationYear(1900);
        ironArmor.SetArmorMaterial("Iron");
        ironArmor.SetArmorType("Full Set");
        ironArmor.SetArmorIsFunctional(true);
        ironArmor.SetArmorWeight(10000);
    }

    Armor ironArmor;
};

TEST_F(ArmorTest, Inheritance) {
    EXPECT_EQ(ironArmor.GetExhibitType(), "Armor");
}

TEST_F(ArmorTest, GettersTest) {
    EXPECT_EQ(ironArmor.GetArmorMaterial(), "Iron");
    EXPECT_EQ(ironArmor.GetArmorType(), "Full Set");
    EXPECT_TRUE(ironArmor.GetArmorIsFunctional());
    EXPECT_EQ(ironArmor.GetArmorWeight(), 10000);
}

TEST_F(ArmorTest, SettersTest) {
    ironArmor.SetArmorMaterial("Chain");
    ironArmor.SetArmorType("Chestplate");
    ironArmor.SetArmorIsFunctional(false);
    ironArmor.SetArmorWeight(3000);

    EXPECT_EQ(ironArmor.GetArmorMaterial(), "Chain");
    EXPECT_EQ(ironArmor.GetArmorType(), "Chestplate");
    EXPECT_FALSE(ironArmor.GetArmorIsFunctional());
    EXPECT_EQ(ironArmor.GetArmorWeight(), 3000);
}

TEST_F(ArmorTest, ConstructorTest) {
    Armor defaultArmor;

    EXPECT_EQ(defaultArmor.GetArmorMaterial(), "");
    EXPECT_EQ(defaultArmor.GetArmorType(), "");
    EXPECT_EQ(defaultArmor.GetArmorWeight(), 0.0);
    EXPECT_FALSE(defaultArmor.GetArmorIsFunctional());
}

TEST_F(ArmorTest, AsExhibitTest) {
    EXPECT_EQ(ironArmor.GetExhibitNumberId(), 11);
    EXPECT_EQ(ironArmor.GetExhibitName(), "Iron Armor Set");
    EXPECT_EQ(ironArmor.GetExhibitCollection(), "Medieval Armors");
    EXPECT_EQ(ironArmor.GetExhibitFoundationYear(), 1900);
}