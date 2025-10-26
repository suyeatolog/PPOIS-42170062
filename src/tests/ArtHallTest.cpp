#include <gtest/gtest.h>
#include "../Halls/ArtHall/ArtHall.h"
#include "../Exhibition/Exhibition.h"

class ArtHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        artHall.SetHallName("Renaissance Gallery");
        artHall.SetHallNumber(1);
        artHall.SetHallArea(150.5);
        artHall.SetHallCapacity(50);
    }

    ArtHall artHall;
    Exhibition exhibition;
};

TEST_F(ArtHallTest, GettetsTest) {
    EXPECT_EQ(artHall.GetHallName(), "Renaissance Gallery");
    EXPECT_EQ(artHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(artHall.GetHallArea(), 150.5);
    EXPECT_EQ(artHall.GetHallCapacity(), 50);
    EXPECT_EQ(artHall.GetHallType(), "ArtHall");
}

TEST_F(ArtHallTest, ArtPeriodTest) {
    artHall.SetArtPeriod("Renaissance");
    EXPECT_EQ(artHall.GetArtPeriod(), "Renaissance");

    artHall.SetArtPeriod("Modern");
    EXPECT_EQ(artHall.GetArtPeriod(), "Modern");
}

TEST_F(ArtHallTest, ConstructorTest) {
    ArtHall defaultArtHall;

    EXPECT_EQ(defaultArtHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultArtHall.GetArtPeriod(), "");
}

TEST_F(ArtHallTest, ExhibitionManagement) {
    exhibition.SetExhibitionName("Masterpieces of Renaissance");

    artHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(artHall.HasExhibition());
    EXPECT_EQ(artHall.GetCurrentExhibition()->GetExhibitionName(), "Masterpieces of Renaissance");
}

TEST_F(ArtHallTest, SettersTest) {
    artHall.SetHallName("Modern Art Gallery");
    artHall.SetHallNumber(2);
    artHall.SetHallArea(200.0);
    artHall.SetHallCapacity(60);
    artHall.SetArtPeriod("Impressionism");

    EXPECT_EQ(artHall.GetHallName(), "Modern Art Gallery");
    EXPECT_EQ(artHall.GetHallNumber(), 2);
    EXPECT_DOUBLE_EQ(artHall.GetHallArea(), 200.0);
    EXPECT_EQ(artHall.GetHallCapacity(), 60);
    EXPECT_EQ(artHall.GetArtPeriod(), "Impressionism");
}