#include <gtest/gtest.h>
#include "../Tours/Tour/Tour.h"
#include "../Visitor/Visitor.h"
#include "../Halls/ArtHall/ArtHall.h"
#include "../Halls/HistoryHall/HistoryHall.h"
#include "../Exceptions/Exceptions.h"

class TourTest : public ::testing::Test {
protected:
    void SetUp() override {
        tour.SetTourName("Masterpieces Tour");
        tour.SetTheme("Art Through Ages");
        tour.SetDuration(90);
        tour.SetMaxVisitors(15);

        artHall.SetHallName("Renaissance Gallery");
        artHall.SetHallNumber(1);

        historyHall.SetHallName("Ancient History");
        historyHall.SetHallNumber(2);

        visitor1.SetVisitorName("Eduard Kichigin");
        visitor2.SetVisitorName("Dexter Morgan");
        visitor3.SetVisitorName("Eugene Kulik");
    }

    Tour tour;
    ArtHall artHall;
    HistoryHall historyHall;
    Visitor visitor1;
    Visitor visitor2;
    Visitor visitor3;
};

TEST_F(TourTest, GettersTest) {
    EXPECT_EQ(tour.GetTourName(), "Masterpieces Tour");
    EXPECT_EQ(tour.GetTheme(), "Art Through Ages");
    EXPECT_EQ(tour.GetDuration(), 90);
    EXPECT_EQ(tour.GetMaxVisitors(), 15);
    EXPECT_EQ(tour.GetHallsCount(), 0);
    EXPECT_EQ(tour.GetVisitorsCount(), 0);
    EXPECT_FALSE(tour.IsFull());
    EXPECT_FALSE(tour.IsActive());
}

TEST_F(TourTest, AddAndRemoveHallsTest) {
    tour.AddHall(&artHall);
    tour.AddHall(&historyHall);

    EXPECT_EQ(tour.GetHallsCount(), 2);

    auto route = tour.GetRoute();
    EXPECT_EQ(route.size(), 2);
    EXPECT_EQ(route[0]->GetHallName(), "Renaissance Gallery");
    EXPECT_EQ(route[1]->GetHallName(), "Ancient History");

    tour.RemoveHall(1);
    EXPECT_EQ(tour.GetHallsCount(), 1);
    EXPECT_EQ(tour.GetRoute()[0]->GetHallName(), "Ancient History");
}

TEST_F(TourTest, InsertHallTest) {
    tour.AddHall(&artHall);
    tour.AddHall(&historyHall);

    ArtHall modernHall;
    modernHall.SetHallName("Modern Art");
    modernHall.SetHallNumber(3);

    tour.InsertHall(1, &modernHall);

    auto route = tour.GetRoute();
    EXPECT_EQ(route.size(), 3);
    EXPECT_EQ(route[0]->GetHallName(), "Renaissance Gallery");
    EXPECT_EQ(route[1]->GetHallName(), "Modern Art");
    EXPECT_EQ(route[2]->GetHallName(), "Ancient History");
}

TEST_F(TourTest, ClearAndReverseRouteTest) {
    tour.AddHall(&artHall);
    tour.AddHall(&historyHall);
    EXPECT_EQ(tour.GetHallsCount(), 2);

    tour.ClearRoute();
    EXPECT_EQ(tour.GetHallsCount(), 0);

    tour.AddHall(&artHall);
    tour.AddHall(&historyHall);
    tour.ReverseRoute();

    auto route = tour.GetRoute();
    EXPECT_EQ(route[0]->GetHallName(), "Ancient History");
    EXPECT_EQ(route[1]->GetHallName(), "Renaissance Gallery");
}

TEST_F(TourTest, AddAndRemoveVisitorsTest) {
    tour.AddVisitor(&visitor1);
    tour.AddVisitor(&visitor2);

    EXPECT_EQ(tour.GetVisitorsCount(), 2);
    EXPECT_FALSE(tour.IsFull());

    auto visitors = tour.GetVisitors();
    EXPECT_EQ(visitors.size(), 2);
    EXPECT_EQ(visitors[0]->GetVisitorName(), "Eduard Kichigin");
    EXPECT_EQ(visitors[1]->GetVisitorName(), "Dexter Morgan");

    tour.RemoveVisitor("Eduard Kichigin");
    EXPECT_EQ(tour.GetVisitorsCount(), 1);
    EXPECT_EQ(tour.GetVisitors()[0]->GetVisitorName(), "Dexter Morgan");

    tour.ClearVisitors();
    EXPECT_EQ(tour.GetVisitorsCount(), 0);
}

TEST_F(TourTest, TourCapacityTest) {
    tour.SetMaxVisitors(2);

    tour.AddVisitor(&visitor1);
    tour.AddVisitor(&visitor2);

    EXPECT_TRUE(tour.IsFull());
    EXPECT_THROW(tour.AddVisitor(&visitor3), TourFullException);
}

TEST_F(TourTest, StartAndEndTourTest) {
    tour.AddHall(&artHall);
    tour.AddVisitor(&visitor1);

    tour.StartTour();

    EXPECT_TRUE(tour.IsActive());
    EXPECT_EQ(tour.GetCurrentHallIndex(), 0);

    Hall* currentHall = tour.GetCurrentHall();
    EXPECT_NE(currentHall, nullptr);
    EXPECT_EQ(currentHall->GetHallName(), "Renaissance Gallery");

    tour.EndTour();

    EXPECT_FALSE(tour.IsActive());
    EXPECT_EQ(tour.GetCurrentHallIndex(), -1);
    EXPECT_EQ(tour.GetCurrentHall(), nullptr);
}

TEST_F(TourTest, MoveThroughHallsTest) {
    tour.AddHall(&artHall);
    tour.AddHall(&historyHall);
    tour.AddVisitor(&visitor1);

    tour.StartTour();

    EXPECT_EQ(tour.GetCurrentHallIndex(), 0);
    EXPECT_EQ(tour.GetCurrentHall()->GetHallName(), "Renaissance Gallery");

    tour.MoveToNextHall();

    EXPECT_EQ(tour.GetCurrentHallIndex(), 1);
    EXPECT_EQ(tour.GetCurrentHall()->GetHallName(), "Ancient History");

    tour.MoveToNextHall();

    EXPECT_FALSE(tour.IsActive());
    EXPECT_EQ(tour.GetCurrentHallIndex(), -1);
}

TEST_F(TourTest, TourExceptionsTest) {
    tour.AddVisitor(&visitor1);
    EXPECT_THROW(tour.StartTour(), EmptyTourRouteException);

    tour.ClearVisitors();
    tour.AddHall(&artHall);
    EXPECT_THROW(tour.StartTour(), EmptyTourRouteException);

    EXPECT_THROW(tour.MoveToNextHall(), TourNotActiveException);

    EXPECT_THROW(tour.EndTour(), TourNotActiveException);

    EXPECT_THROW(tour.AddHall(nullptr), InvalidTourParameterException);

    EXPECT_THROW(tour.AddVisitor(nullptr), InvalidTourParameterException);
}

TEST_F(TourTest, InvalidPositionInsertTest) {
    EXPECT_THROW(tour.InsertHall(-1, &artHall), InvalidTourParameterException);
    EXPECT_THROW(tour.InsertHall(10, &artHall), InvalidTourParameterException);
}