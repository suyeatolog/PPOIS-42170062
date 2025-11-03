//
// Created by user on 31.10.2025.
//
#include <gtest/gtest.h>
#include "../Halls/WarHall/WarHall.h"
#include "../Exhibition/Exhibition.h"

class WarHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        warHall.SetHallName("World War II Hall");
        warHall.SetHallNumber(1);
        warHall.SetHallArea(150.5);
        warHall.SetHallCapacity(50);
    }

    WarHall warHall;
    Exhibition exhibition;
};

TEST_F(WarHallTest, GettersTest) {
    EXPECT_EQ(warHall.GetHallName(), "World War II Hall");
    EXPECT_EQ(warHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(warHall.GetHallArea(), 150.5);
    EXPECT_EQ(warHall.GetHallCapacity(), 50);
    EXPECT_EQ(warHall.GetHallType(), "WarHall");
}

TEST_F(WarHallTest, ArtPeriodTest) {
    warHall.SetWarName("World War II");
    EXPECT_EQ(warHall.GetWarName(), "World War II");
}

TEST_F(WarHallTest, ConstructorTest) {
    WarHall defaultWarHall;

    EXPECT_EQ(defaultWarHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultWarHall.GetWarName(), "");
}
TEST_F(WarHallTest, ExhibitionManagementTest) {
    exhibition.SetExhibitionName("Artifacts of WWII");

    warHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(warHall.HasExhibition());
    EXPECT_EQ(warHall.GetCurrentExhibition()->GetExhibitionName(), "Artifacts of WWII");
}