//
// Created by user on 27.10.2025.
//
#include <gtest/gtest.h>
#include "../Halls/HistoryHall/HistoryHall.h"
#include "../Exhibition/Exhibition.h"

class HistoryHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        historyHall.SetHallName("History of Stone Age");
        historyHall.SetHallNumber(2);
        historyHall.SetHallArea(150.6);
        historyHall.SetHallCapacity(30);
    }

    HistoryHall historyHall;
    Exhibition exhibition;
};

TEST_F(HistoryHallTest, GettersTest) {
    EXPECT_EQ(historyHall.GetHallName(), "History of Stone Age");
    EXPECT_EQ(historyHall.GetHallNumber(), 2);
    EXPECT_DOUBLE_EQ(historyHall.GetHallArea(), 150.6);
    EXPECT_EQ(historyHall.GetHallCapacity(), 30);
    EXPECT_EQ(historyHall.GetHallType(), "HistoryHall");
}

TEST_F(HistoryHallTest, HistoricalPeriodTest) {
    historyHall.SetHistoricalPeriod("Middle Age");
    EXPECT_EQ(historyHall.GetHistoricalPeriod(), "Middle Age");

    historyHall.SetHistoricalPeriod("Modern History");
    EXPECT_EQ(historyHall.GetHistoricalPeriod(), "Modern History");
}

TEST_F(HistoryHallTest, ConstructorTest) {
    HistoryHall defaultArtHall;

    EXPECT_EQ(defaultArtHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultArtHall.GetHistoricalPeriod(), "");
}

TEST_F(HistoryHallTest, ExhibitionManagement) {
    exhibition.SetExhibitionName("Tools of Stone age");

    historyHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(historyHall.HasExhibition());
    EXPECT_EQ(historyHall.GetCurrentExhibition()->GetExhibitionName(), "Tools of Stone age");
}

TEST_F(HistoryHallTest, SettersTest) {
    historyHall.SetHallName("Modern History");
    historyHall.SetHallNumber(3);
    historyHall.SetHallArea(200.0);
    historyHall.SetHallCapacity(60);
    historyHall.SetHistoricalPeriod("Modern age");

    EXPECT_EQ(historyHall.GetHallName(), "Modern History");
    EXPECT_EQ(historyHall.GetHallNumber(), 3);
    EXPECT_DOUBLE_EQ(historyHall.GetHallArea(), 200.0);
    EXPECT_EQ(historyHall.GetHallCapacity(), 60);
    EXPECT_EQ(historyHall.GetHistoricalPeriod(), "Modern age");
}