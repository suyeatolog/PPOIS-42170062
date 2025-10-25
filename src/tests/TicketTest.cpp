#include <gtest/gtest.h>
#include "../AccessControl/Ticket/Ticket.h"

class TicketTest : public ::testing::Test {
protected:
    void SetUp() override {
        testTicket.SetTicketName("Ticket");
        testTicket.SetTicketNumber(1);
        testTicket.SetTicketPrice(5);
    }

    Ticket testTicket;
};

TEST_F(TicketTest, ConstructorTest) {
    Ticket defaultTicket;
    EXPECT_EQ(defaultTicket.GetTicketName(), "");
    EXPECT_EQ(defaultTicket.GetTicketNumber(), 0);
    EXPECT_EQ(defaultTicket.GetTicketPrice(), 0);
}

TEST_F(TicketTest, SettersGettersTest) {
    testTicket.SetTicketName("Ticket2");
    testTicket.SetTicketNumber(2);
    testTicket.SetTicketPrice(10);

    EXPECT_EQ(testTicket.GetTicketName(), "Ticket2");
    EXPECT_EQ(testTicket.GetTicketNumber(), 2);
    EXPECT_EQ(testTicket.GetTicketPrice(), 10);
}