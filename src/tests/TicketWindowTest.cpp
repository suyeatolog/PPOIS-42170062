#include <gtest/gtest.h>
#include "../AccessControl/TicketWindow/TicketWindow.h"

class TicketWindowTest : public ::testing::Test {
protected:
    TicketWindow testTicketWindow;
    Ticket testTicket;
    Visitor testVisitor;

    void SetUp() override {
        testTicketWindow.SetAmountOfTickets(150);
        testTicket.SetTicketName("Museum Ticket");
        testTicket.SetTicketNumber(42170062);
        testTicket.SetTicketPrice(5);
        testVisitor.SetVisitorName("Zhenya");
        testVisitor.SetVisitorAge(18);
    }
};

TEST_F(TicketWindowTest, ConstructorTest) {
    TicketWindow testTicketWindow;
    EXPECT_EQ(testTicketWindow.GetAmountOfTickets(), 0);
    EXPECT_EQ(testTicketWindow.GetTotalGain(), 0);
}

TEST_F(TicketWindowTest, SettersGettersTest) {
    testTicketWindow.SetAmountOfTickets(200);
    EXPECT_EQ(testTicketWindow.GetAmountOfTickets(), 200);
}

TEST_F(TicketWindowTest, SellingTicketTest) {
    testTicketWindow.SellTicket(testVisitor, testTicket);
    EXPECT_EQ(testTicketWindow.GetAmountOfTickets(), 149);
    EXPECT_EQ(testTicketWindow.GetTotalGain(), 5);
    EXPECT_TRUE(testVisitor.GetVisitorHasTicket());
}