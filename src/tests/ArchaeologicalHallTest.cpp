#include <gtest/gtest.h>
#include "../Halls/ArchaeologicalHall/ArchaeologicalHall.h"
#include "../Exhibition/Exhibition.h"

class ArchaeologicalHallTest : public ::testing::Test {
protected:
    void SetUp() override {
        archaeologicalHall.SetHallName("Ancient Bones Hall");
        archaeologicalHall.SetHallNumber(1);
        archaeologicalHall.SetHallArea(150.5);
        archaeologicalHall.SetHallCapacity(50);
    }

    ArchaeologicalHall archaeologicalHall;
    Exhibition exhibition;
};

TEST_F(ArchaeologicalHallTest, GettersTest) {
    EXPECT_EQ(archaeologicalHall.GetHallName(), "Ancient Bones Hall");
    EXPECT_EQ(archaeologicalHall.GetHallNumber(), 1);
    EXPECT_DOUBLE_EQ(archaeologicalHall.GetHallArea(), 150.5);
    EXPECT_EQ(archaeologicalHall.GetHallCapacity(), 50);
    EXPECT_EQ(archaeologicalHall.GetHallType(), "ArchaeologicalHall");
}

TEST_F(ArchaeologicalHallTest, ArchaeologicalEraTest) {
    archaeologicalHall.SetArchaeologicalEra("Mesozoic period");
    EXPECT_EQ(archaeologicalHall.GetArchaeologicalEra(), "Mesozoic period");
}

TEST_F(ArchaeologicalHallTest, ConstructorTest) {
    ArchaeologicalHall defaultArchaeologicalHall;

    EXPECT_EQ(defaultArchaeologicalHall.GetHallCapacity(), 0);
    EXPECT_EQ(defaultArchaeologicalHall.GetArchaeologicalEra(), "");
}

TEST_F(ArchaeologicalHallTest, ExhibitionManagementTest) {
    exhibition.SetExhibitionName("Dinosaur Bones");

    archaeologicalHall.SetCurrentExhibition(&exhibition);

    EXPECT_TRUE(archaeologicalHall.HasExhibition());
    EXPECT_EQ(archaeologicalHall.GetCurrentExhibition()->GetExhibitionName(), "Dinosaur Bones");
}