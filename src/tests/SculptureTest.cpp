#include <gtest/gtest.h>
#include "../Sculpture/Sculpture.h"

class SculptureTest : public ::testing::Test {
protected:
    void SetUp() override {
        sculpture.SetSculpturist("Michelangelo");
        sculpture.SetExhibitNumberId(2);
        sculpture.SetExhibitName("David");
        sculpture.SetExhibitCollection("Renaissance Sculpture");
        sculpture.SetExhibitFoundationYear(1504);
        sculpture.SetMaterial("Marble");
        sculpture.SetWeight(5572.5);
        sculpture.SetFragile(true);
        sculpture.SetLength(200);
        sculpture.SetWidth(100);
        sculpture.SetHeight(517);
    }

    Sculpture sculpture;
};

TEST_F(SculptureTest, Inheritance) {
    EXPECT_EQ(sculpture.GetExhibitType(), "Sculpture");
}

TEST_F(SculptureTest, ConstructorTest) {
    Sculpture defaultSculpture;

    EXPECT_EQ(defaultSculpture.GetSculpturist(), "");
    EXPECT_EQ(defaultSculpture.GetMaterial(), "");
    EXPECT_DOUBLE_EQ(defaultSculpture.GetWeight(), 0.0);
    EXPECT_FALSE(defaultSculpture.IsFragile());
    EXPECT_EQ(defaultSculpture.GetLength(), 0);
    EXPECT_EQ(defaultSculpture.GetWidth(), 0);
    EXPECT_EQ(defaultSculpture.GetHeight(), 0);
}

TEST_F(SculptureTest, GettersTest) {
    EXPECT_EQ(sculpture.GetSculpturist(), "Michelangelo");
    EXPECT_EQ(sculpture.GetMaterial(), "Marble");
    EXPECT_DOUBLE_EQ(sculpture.GetWeight(), 5572.5);
    EXPECT_TRUE(sculpture.IsFragile());
    EXPECT_EQ(sculpture.GetLength(), 200);
    EXPECT_EQ(sculpture.GetWidth(), 100);
    EXPECT_EQ(sculpture.GetHeight(), 517);
}

TEST_F(SculptureTest, SettersTest) {
    sculpture.SetMaterial("Bronze");
    sculpture.SetWeight(2500.0);
    sculpture.SetFragile(false);
    sculpture.SetLength(150);
    sculpture.SetWidth(80);
    sculpture.SetHeight(300);

    EXPECT_EQ(sculpture.GetMaterial(), "Bronze");
    EXPECT_DOUBLE_EQ(sculpture.GetWeight(), 2500.0);
    EXPECT_FALSE(sculpture.IsFragile());
    EXPECT_EQ(sculpture.GetLength(), 150);
    EXPECT_EQ(sculpture.GetWidth(), 80);
    EXPECT_EQ(sculpture.GetHeight(), 300);
}

TEST_F(SculptureTest, AsExhibitTest) {
    EXPECT_EQ(sculpture.GetExhibitNumberId(), 2);
    EXPECT_EQ(sculpture.GetExhibitName(), "David");
    EXPECT_EQ(sculpture.GetExhibitCollection(), "Renaissance Sculpture");
    EXPECT_EQ(sculpture.GetExhibitFoundationYear(), 1504);
}