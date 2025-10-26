#include <gtest/gtest.h>
#include "../AccessControl/Checkpoint/Checkpoint.h"
#include "../Exceptions/Exceptions.h"
#include "../Visitor/Visitor.h"

class CheckpointTest : public ::testing::Test {
protected:
    void SetUp() override {
        visitorWithTicket.SetVisitorName("Eugene");
        visitorWithTicket.SetVisitorAge(30);
        visitorWithTicket.SetVisitorHasTicket(true);

        visitorWithoutTicket.SetVisitorName("Jane Doe");
        visitorWithoutTicket.SetVisitorAge(25);
        visitorWithoutTicket.SetVisitorHasTicket(false);
    }

    Checkpoint checkpoint;
    Visitor visitorWithTicket;
    Visitor visitorWithoutTicket;
};

TEST_F(CheckpointTest, AccessTest1) {
    checkpoint.CheckAccess(visitorWithTicket);
    EXPECT_TRUE(visitorWithTicket.GetVisitorHasAccess());
}

TEST_F(CheckpointTest, AccessTest2) {
    EXPECT_THROW(checkpoint.CheckAccess(visitorWithoutTicket), NoTicketException);
}