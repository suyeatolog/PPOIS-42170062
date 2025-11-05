#include <gtest/gtest.h>

#include "../Exceptions/Exceptions.h"
#include "../Visitor/Visitor.h"
#include "../AccessControl/Guard/Guard.h"
#include "../AccessControl/TicketWindow/TicketWindow.h"

class GuardTest : public ::testing::Test {
protected:
    void SetUp() override {
        guard.SetGuardName("Ivan");
        guard.SetGuardAge(22);
        visitor.SetVisitorHasTicket(true);
        visitor.SetVisitorIsSuspicious(true);
        visitor.SetVisitorIsDangerous(true);
        ticketWindow.SetAmountOfTickets(199);
    }

    Guard guard;
    Visitor visitor;
    TicketWindow ticketWindow;
};

TEST_F(GuardTest, GettersSettersTest) {
    EXPECT_EQ(guard.GetGuardName(), "Ivan");
    EXPECT_EQ(guard.GetGuardAge(), 22);

    guard.SetGuardName("Ilya");
    EXPECT_EQ(guard.GetGuardName(), "Ilya");
    guard.SetGuardAge(20);
    EXPECT_EQ(guard.GetGuardAge(), 20);
}

TEST_F(GuardTest, ExceptionsTest) {
    EXPECT_THROW(guard.SetGuardName(""), EmptyNameException);
    EXPECT_THROW(guard.SetGuardAge(-1), InvalidAgeException);
    EXPECT_THROW(guard.SetGuardAge(151), InvalidAgeException);
}

TEST_F(GuardTest, CheckingVisitorTest) {
    guard.CheckSuspiciousVisitor(visitor, ticketWindow);
    EXPECT_FALSE(visitor.GetVisitorHasTicket());
    EXPECT_FALSE(visitor.GetVisitorHasAccess());
    EXPECT_EQ(ticketWindow.GetAmountOfTickets(), 200);

    visitor.SetVisitorIsSuspicious(true);
    visitor.SetVisitorIsDangerous(false);
    visitor.SetVisitorHasTicket(true);
    visitor.SetVisitorHasAccess(true);

    guard.CheckSuspiciousVisitor(visitor, ticketWindow);
    EXPECT_TRUE(visitor.GetVisitorHasTicket());
    EXPECT_TRUE(visitor.GetVisitorHasAccess());
    EXPECT_EQ(ticketWindow.GetAmountOfTickets(), 200);
    EXPECT_FALSE(visitor.GetVisitorIsSuspicious());
}