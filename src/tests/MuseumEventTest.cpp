#include <gtest/gtest.h>
#include "../MuseumEvent/MuseumEvent.h"
#include "../Halls/ArtHall/ArtHall.h"
#include "../Visitor/Visitor.h"
#include "../Exceptions/Exceptions.h"

class MuseumEventTest : public ::testing::Test {
protected:
    void SetUp() override {
        event.SetEventName("Art Lecture");
        event.SetEventType("Lecture");
        event.SetEventDescription("Introduction to Renaissance Art");
        event.SetMaxParticipants(3);
        event.SetDuration(90);
        event.SetHall(&hall);

        visitor1.SetVisitorName("Kirill Poplavskiy");
        visitor2.SetVisitorName("Artyom Bashura");
        visitor3.SetVisitorName("Eugene Kulik");
        visitor4.SetVisitorName("Dmitry Burbas");
    }

    MuseumEvent event;
    ArtHall hall;
    Visitor visitor1;
    Visitor visitor2;
    Visitor visitor3;
    Visitor visitor4;
};

TEST_F(MuseumEventTest, GettersTest) {
    EXPECT_EQ(event.GetEventName(), "Art Lecture");
    EXPECT_EQ(event.GetEventType(), "Lecture");
    EXPECT_EQ(event.GetEventDescription(), "Introduction to Renaissance Art");
    EXPECT_EQ(event.GetMaxParticipants(), 3);
    EXPECT_EQ(event.GetDuration(), 90);
    EXPECT_EQ(event.GetHall(), &hall);
    EXPECT_EQ(event.CountParticipants(), 0);
    EXPECT_FALSE(event.IsFull());
    EXPECT_FALSE(event.IsActive());
}

TEST_F(MuseumEventTest, AddParticipantsTest) {
    event.AddParticipant(&visitor1);
    event.AddParticipant(&visitor2);

    EXPECT_EQ(event.CountParticipants(), 2);
    EXPECT_FALSE(event.IsFull());

    auto participants = event.GetParticipants();
    EXPECT_EQ(participants.size(), 2);
    EXPECT_EQ(participants[0]->GetVisitorName(), "Kirill Poplavskiy");
    EXPECT_EQ(participants[1]->GetVisitorName(), "Artyom Bashura");
}

TEST_F(MuseumEventTest, RemoveParticipantTest) {
    event.AddParticipant(&visitor1);
    event.AddParticipant(&visitor2);
    event.AddParticipant(&visitor3);

    EXPECT_EQ(event.CountParticipants(), 3);

    event.RemoveParticipant("Kirill Poplavskiy");
    EXPECT_EQ(event.CountParticipants(), 2);

    auto participants = event.GetParticipants();
    EXPECT_EQ(participants[0]->GetVisitorName(), "Artyom Bashura");
    EXPECT_EQ(participants[1]->GetVisitorName(), "Eugene Kulik");
}

TEST_F(MuseumEventTest, ParticipantRegistrationCheckTest) {
    EXPECT_FALSE(event.IsParticipantRegistered("Kirill Poplavskiy"));

    event.AddParticipant(&visitor1);
    EXPECT_TRUE(event.IsParticipantRegistered("Kirill Poplavskiy"));
    EXPECT_FALSE(event.IsParticipantRegistered("Artyom Bashura"));
}

TEST_F(MuseumEventTest, CapacityLimitsTest) {
    event.AddParticipant(&visitor1);
    event.AddParticipant(&visitor2);
    event.AddParticipant(&visitor3);

    EXPECT_TRUE(event.IsFull());
    EXPECT_EQ(event.CountParticipants(), 3);

    EXPECT_THROW(event.AddParticipant(&visitor4), FullParticipantsException);
}

TEST_F(MuseumEventTest, DuplicateRegistrationExceptionTest) {
    event.AddParticipant(&visitor1);

    EXPECT_THROW(event.AddParticipant(&visitor1), VisitorAlreadyRegistered);
}

TEST_F(MuseumEventTest, InvalidVisitorExceptionTest) {
    EXPECT_THROW(event.AddParticipant(nullptr), InvalidVisitorParameterException);
}

TEST_F(MuseumEventTest, StartAndEndEventTest) {
    EXPECT_FALSE(event.IsActive());

    event.StartEvent();
    EXPECT_TRUE(event.IsActive());

    event.EndEvent();
    EXPECT_FALSE(event.IsActive());
}

TEST_F(MuseumEventTest, StartEventWithoutHallTest) {
    MuseumEvent eventWithoutHall;
    eventWithoutHall.SetEventName("Test Event");

    eventWithoutHall.StartEvent();
    EXPECT_FALSE(eventWithoutHall.IsActive());
}

TEST_F(MuseumEventTest, ManualActivityControlTest) {
    event.SetIsActive(true);
    EXPECT_TRUE(event.IsActive());

    event.SetIsActive(false);
    EXPECT_FALSE(event.IsActive());
}

TEST_F(MuseumEventTest, SettersTest) {
    event.SetEventName("New Event Name");
    event.SetEventType("Workshop");
    event.SetEventDescription("New Description");
    event.SetMaxParticipants(10);
    event.SetDuration(120);

    EXPECT_EQ(event.GetEventName(), "New Event Name");
    EXPECT_EQ(event.GetEventType(), "Workshop");
    EXPECT_EQ(event.GetEventDescription(), "New Description");
    EXPECT_EQ(event.GetMaxParticipants(), 10);
    EXPECT_EQ(event.GetDuration(), 120);
}

TEST_F(MuseumEventTest, RemoveNonExistentParticipantTest) {
    event.AddParticipant(&visitor1);
    EXPECT_EQ(event.CountParticipants(), 1);

    event.RemoveParticipant("Non Existent");
    EXPECT_EQ(event.CountParticipants(), 1);
}

