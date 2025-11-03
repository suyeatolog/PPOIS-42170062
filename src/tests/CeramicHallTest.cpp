#include <gtest/gtest.h>
#include "../Halls/CeramicHall/CeramicHall.h"
#include "../Exhibition/Exhibition.h"

class CeramicHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        ceramicHall.SetHallName("Vase Hall");
        ceramicHall.SetHallNumber(1);
        ceramicHall.SetHallArea(150.5);
        ceramicHall.SetHallCapacity(50);
    }

    CeramicHall ceramicHall;
    Exhibition exhibition;
};

TEST_F(CeramicHallTest, GettersTest) {
    EXPECT_EQ(ceramicHall.GetHallName(), "Vase Hall");
    EXPECT_EQ(ceramicHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(ceramicHall.GetHallArea(), 150.5);
    EXPECT_EQ(ceramicHall.GetHallCapacity(), 50);
    EXPECT_EQ(ceramicHall.GetHallType(), "CeramicHall");
}

TEST_F(CeramicHallTest, VaseEraTest) {
    ceramicHall.SetVaseEra("Ancient Era");
    EXPECT_EQ(ceramicHall.GetVaseEra(), "Ancient Era");
}

TEST_F(CeramicHallTest, ConstructorTest) {
    CeramicHall defaultCeramicHall;

    EXPECT_EQ(defaultCeramicHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultCeramicHall.GetVaseEra(), "");
}

TEST_F(CeramicHallTest, ExhibitionManagementTest) {
    exhibition.SetExhibitionName("Romanian Vases");

    ceramicHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(ceramicHall.HasExhibition());
    EXPECT_EQ(ceramicHall.GetCurrentExhibition()->GetExhibitionName(), "Romanian Vases");
}