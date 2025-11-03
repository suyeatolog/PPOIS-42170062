#include <gtest/gtest.h>
#include "../Halls/CostumeHall/CostumeHall.h"
#include "../Exhibition/Exhibition.h"

class CostumeHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        costumeHall.SetHallName("Slavic Costumes Collection");
        costumeHall.SetHallNumber(1);
        costumeHall.SetHallArea(150.5);
        costumeHall.SetHallCapacity(50);
    }

    CostumeHall costumeHall;
    Exhibition exhibition;
};

TEST_F(CostumeHallTest, GettersTest) {
    EXPECT_EQ(costumeHall.GetHallName(), "Slavic Costumes Collection");
    EXPECT_EQ(costumeHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(costumeHall.GetHallArea(), 150.5);
    EXPECT_EQ(costumeHall.GetHallCapacity(), 50);
    EXPECT_EQ(costumeHall.GetHallType(), "CostumeHall");
}

TEST_F(CostumeHallTest, CostumePeriodTest) {
    costumeHall.SetCostumeEra("Medieval");
    EXPECT_EQ(costumeHall.GetCostumeEra(), "Medieval");
}

TEST_F(CostumeHallTest, ConstructorTest) {
    CostumeHall defaultArtHall;

    EXPECT_EQ(defaultArtHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultArtHall.GetCostumeEra(), "");
}

TEST_F(CostumeHallTest, ExhibitionManagementTest) {
    exhibition.SetExhibitionName("Dresses");

    costumeHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(costumeHall.HasExhibition());
    EXPECT_EQ(costumeHall.GetCurrentExhibition()->GetExhibitionName(), "Dresses");
}

TEST_F(CostumeHallTest, SettersTest) {
    costumeHall.SetHallName("Modern Suits Gallery");
    costumeHall.SetHallNumber(2);
    costumeHall.SetHallArea(200.0);
    costumeHall.SetHallCapacity(60);
    costumeHall.SetCostumeEra("Modern");

    EXPECT_EQ(costumeHall.GetHallName(), "Modern Suits Gallery");
    EXPECT_EQ(costumeHall.GetHallNumber(), 2);
    EXPECT_DOUBLE_EQ(costumeHall.GetHallArea(), 200.0);
    EXPECT_EQ(costumeHall.GetHallCapacity(), 60);
    EXPECT_EQ(costumeHall.GetCostumeEra(), "Modern");
}