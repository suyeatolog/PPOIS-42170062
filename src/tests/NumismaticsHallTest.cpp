#include <gtest/gtest.h>
#include "../Halls/NumismaticsHall/NumismaticsHall.h"
#include "../Exhibition/Exhibition.h"

class NumismaticsHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        numismaticsHall.SetHallName("Coins Hall");
        numismaticsHall.SetHallNumber(1);
        numismaticsHall.SetHallArea(150.5);
        numismaticsHall.SetHallCapacity(50);
    }

    NumismaticsHall numismaticsHall;
    Exhibition exhibition;
};

TEST_F(NumismaticsHallTest, GettersTest) {
    EXPECT_EQ(numismaticsHall.GetHallName(), "Coins Hall");
    EXPECT_EQ(numismaticsHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(numismaticsHall.GetHallArea(), 150.5);
    EXPECT_EQ(numismaticsHall.GetHallCapacity(), 50);
    EXPECT_EQ(numismaticsHall.GetHallType(), "NumismaticsHall");
}

TEST_F(NumismaticsHallTest, CoinEraTest) {
    numismaticsHall.SetCoinEra("XX century");
    EXPECT_EQ(numismaticsHall.GetCoinEra(), "XX century");
}

TEST_F(NumismaticsHallTest, ConstructorTest) {
    NumismaticsHall defaultNumismaticsHall;

    EXPECT_EQ(defaultNumismaticsHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultNumismaticsHall.GetCoinEra(), "");
}

TEST_F(NumismaticsHallTest, ExhibitionManagementTest) {
    exhibition.SetExhibitionName("Chervonets collection");

    numismaticsHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(numismaticsHall.HasExhibition());
    EXPECT_EQ(numismaticsHall.GetCurrentExhibition()->GetExhibitionName(), "Chervonets collection");
}