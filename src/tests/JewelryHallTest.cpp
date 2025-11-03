#include <gtest/gtest.h>
#include "../Halls/JewelryHall/JewelryHall.h"
#include "../Exhibition/Exhibition.h"

class JewelryHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        jewelryHall.SetHallName("Rings collection");
        jewelryHall.SetHallNumber(1);
        jewelryHall.SetHallArea(150.5);
        jewelryHall.SetHallCapacity(50);
    }

    JewelryHall jewelryHall;
    Exhibition exhibition;
};

TEST_F(JewelryHallTest, GettersTest) {
    EXPECT_EQ(jewelryHall.GetHallName(), "Rings collection");
    EXPECT_EQ(jewelryHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(jewelryHall.GetHallArea(), 150.5);
    EXPECT_EQ(jewelryHall.GetHallCapacity(), 50);
    EXPECT_EQ(jewelryHall.GetHallType(), "JewelryHall");
}

TEST_F(JewelryHallTest, JewelryEraTest) {
    jewelryHall.SetJewelryEra("Victorian");
    EXPECT_EQ(jewelryHall.GetJewelryEra(), "Victorian");
}

TEST_F(JewelryHallTest, ConstructorTest) {
    JewelryHall defaultJewelryHall;

    EXPECT_EQ(defaultJewelryHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultJewelryHall.GetJewelryEra(), "");
}

TEST_F(JewelryHallTest, ExhibitionManagementTest) {
    exhibition.SetExhibitionName("Masterpieces of Victorian Era Jewelry");

    jewelryHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(jewelryHall.HasExhibition());
    EXPECT_EQ(jewelryHall.GetCurrentExhibition()->GetExhibitionName(), "Masterpieces of Victorian Era Jewelry");
}

TEST_F(JewelryHallTest, SettersTest) {
    jewelryHall.SetHallName("Modern Art Gallery");
    jewelryHall.SetHallNumber(2);
    jewelryHall.SetHallArea(200.0);
    jewelryHall.SetHallCapacity(60);
    jewelryHall.SetJewelryEra("Modern Era");

    EXPECT_EQ(jewelryHall.GetHallName(), "Modern Art Gallery");
    EXPECT_EQ(jewelryHall.GetHallNumber(), 2);
    EXPECT_DOUBLE_EQ(jewelryHall.GetHallArea(), 200.0);
    EXPECT_EQ(jewelryHall.GetHallCapacity(), 60);
    EXPECT_EQ(jewelryHall.GetJewelryEra(), "Modern Era");
}