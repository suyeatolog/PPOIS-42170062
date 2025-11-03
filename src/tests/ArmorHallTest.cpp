#include <gtest/gtest.h>
#include "../Halls/ArmorHall/ArmorHall.h"
#include "../Exhibition/Exhibition.h"

class ArmorHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        armorHall.SetHallName("Full set Armor Hall");
        armorHall.SetHallNumber(1);
        armorHall.SetHallArea(150.5);
        armorHall.SetHallCapacity(50);
    }

    ArmorHall armorHall;
    Exhibition exhibition;
};

TEST_F(ArmorHallTest, GettersTest) {
    EXPECT_EQ(armorHall.GetHallName(), "Full set Armor Hall");
    EXPECT_EQ(armorHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(armorHall.GetHallArea(), 150.5);
    EXPECT_EQ(armorHall.GetHallCapacity(), 50);
    EXPECT_EQ(armorHall.GetHallType(), "ArmorHall");
}

TEST_F(ArmorHallTest, ArmorPeriodTest) {
    armorHall.SetArmorEra("Medieval");
    EXPECT_EQ(armorHall.GetArmorEra(), "Medieval");
}

TEST_F(ArmorHallTest, ConstructorTest) {
    ArmorHall defaultArtHall;

    EXPECT_EQ(defaultArtHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultArtHall.GetArmorEra(), "");
}

TEST_F(ArmorHallTest, ExhibitionManagementTest) {
    exhibition.SetExhibitionName("Crusaders Armor Sets");

    armorHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(armorHall.HasExhibition());
    EXPECT_EQ(armorHall.GetCurrentExhibition()->GetExhibitionName(), "Crusaders Armor Sets");
}

TEST_F(ArmorHallTest, SettersTest) {
    armorHall.SetHallName("Modern Armor Gallery");
    armorHall.SetHallNumber(2);
    armorHall.SetHallArea(200.0);
    armorHall.SetHallCapacity(60);
    armorHall.SetArmorEra("Modern Armor");

    EXPECT_EQ(armorHall.GetHallName(), "Modern Armor Gallery");
    EXPECT_EQ(armorHall.GetHallNumber(), 2);
    EXPECT_DOUBLE_EQ(armorHall.GetHallArea(), 200.0);
    EXPECT_EQ(armorHall.GetHallCapacity(), 60);
    EXPECT_EQ(armorHall.GetArmorEra(), "Modern Armor");
}