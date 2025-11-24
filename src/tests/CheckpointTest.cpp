#include <gtest/gtest.h>
#include "../AccessControl/Checkpoint/Checkpoint.h"
#include "../Exceptions/Exceptions.h"
#include "../Visitor/Visitor.h"
#include "../AccessControl/TicketWindow/TicketWindow.h"
#include "../AccessControl/Guard/Guard.h"

class CheckpointTest : public ::testing::Test {
protected:
    void SetUp() override {
        checkpoint.SetCheckpointNumber(1);
        visitorWithTicket.SetVisitorName("Eugene");
        visitorWithTicket.SetVisitorAge(30);
        visitorWithTicket.SetVisitorHasTicket(true);

        visitorWithoutTicket.SetVisitorName("Jane Doe");
        visitorWithoutTicket.SetVisitorAge(25);
        visitorWithoutTicket.SetVisitorHasTicket(false);
    }

    Checkpoint checkpoint;
    TicketWindow ticketWindow;
    Guard guard;
    Visitor visitorWithTicket;
    Visitor visitorWithoutTicket;
    Visitor visitor;
};

TEST_F(CheckpointTest, GetterSetterTest) {
    EXPECT_EQ(checkpoint.GetCheckpointNumber(), 1);

    checkpoint.SetCheckpointNumber(2);
    EXPECT_EQ(checkpoint.GetCheckpointNumber(), 2);
}

TEST_F(CheckpointTest, AccessTest1) {
    checkpoint.CheckAccess(visitorWithTicket, guard, ticketWindow);
    EXPECT_TRUE(visitorWithTicket.GetVisitorHasAccess());
}

TEST_F(CheckpointTest, AccessTest2) {
    EXPECT_THROW(checkpoint.CheckAccess(visitorWithoutTicket, guard, ticketWindow), NoTicketException);
}

TEST_F(CheckpointTest, RetakingTicketTest) {
    visitor.SetVisitorHasTicket(true);
    visitor.SetVisitorIsSuspicious(true);
    visitor.SetVisitorIsDangerous(true);
    EXPECT_THROW(checkpoint.CheckAccess(visitor, guard, ticketWindow), NoTicketException);
}