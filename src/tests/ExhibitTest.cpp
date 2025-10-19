#include <gtest/gtest.h>
#include "../Exhibit/Exhibit.h"

class ExhibitTest : public ::testing::Test {
protected:
    void SetUp() override {
        Exhibit.SetExhibitNumberId(1);
        Exhibit.SetExhibitName("Test Exhibit");
        Exhibit.SetExhibitCollection("Test Collection");
        Exhibit.SetExhibitFoundationYear(2000);
    }

    class TestExhibit : public Exhibit {
    public:
        std::string GetExhibitType() const override {
            return "Test Type";
        }
    };

    TestExhibit Exhibit;
};

TEST_F(ExhibitTest, ConstructorTest) {
    TestExhibit defaultExhibit;

    EXPECT_EQ(defaultExhibit.GetExhibitNumberId(), 0);
    EXPECT_EQ(defaultExhibit.GetExhibitName(), "");
    EXPECT_EQ(defaultExhibit.GetExhibitCollection(), "");
    EXPECT_EQ(defaultExhibit.GetExhibitFoundationYear(), 0);
}

TEST_F(ExhibitTest, GettersTest) {
    EXPECT_EQ(Exhibit.GetExhibitNumberId(), 1);
    EXPECT_EQ(Exhibit.GetExhibitName(), "Test Exhibit");
    EXPECT_EQ(Exhibit.GetExhibitCollection(), "Test Collection");
    EXPECT_EQ(Exhibit.GetExhibitFoundationYear(), 2000);
    EXPECT_EQ(Exhibit.GetExhibitType(), "Test Type");
}

TEST_F(ExhibitTest, SettersTest) {
    Exhibit.SetExhibitNumberId(42);
    Exhibit.SetExhibitName("New Name");
    Exhibit.SetExhibitCollection("New Collection");
    Exhibit.SetExhibitFoundationYear(1999);

    EXPECT_EQ(Exhibit.GetExhibitNumberId(), 42);
    EXPECT_EQ(Exhibit.GetExhibitName(), "New Name");
    EXPECT_EQ(Exhibit.GetExhibitCollection(), "New Collection");
    EXPECT_EQ(Exhibit.GetExhibitFoundationYear(), 1999);
}