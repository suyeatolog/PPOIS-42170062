#include <gtest/gtest.h>
#include "../AncientTool/AncientTool.h"

class AncientToolTest : public ::testing::Test {
protected:
    void SetUp() override {
        tool.SetExhibitNumberId(6);
        tool.SetExhibitName("Stone Axe");
        tool.SetExhibitCollection("Prehistoric Tools");
        tool.SetExhibitFoundationYear(-3000);
        tool.SetPurpose("Hunting");
        tool.SetMaterial("Flint");
    }

    AncientTool tool;
};

TEST_F(AncientToolTest, Inheritance) {
    EXPECT_EQ(tool.GetExhibitType(), "AncientTool");
}

TEST_F(AncientToolTest, GettersTest) {
    EXPECT_EQ(tool.GetPurpose(), "Hunting");
    EXPECT_EQ(tool.GetMaterial(), "Flint");
}

TEST_F(AncientToolTest, SettersTest) {
    tool.SetPurpose("Farming");
    tool.SetMaterial("Bronze");

    EXPECT_EQ(tool.GetPurpose(), "Farming");
    EXPECT_EQ(tool.GetMaterial(), "Bronze");
}

TEST_F(AncientToolTest, ConstructorTest) {
    AncientTool defaultTool;

    EXPECT_EQ(defaultTool.GetPurpose(), "");
    EXPECT_EQ(defaultTool.GetMaterial(), "");
}

TEST_F(AncientToolTest, ExhibitPropertiesPreserved) {
    EXPECT_EQ(tool.GetExhibitNumberId(), 6);
    EXPECT_EQ(tool.GetExhibitName(), "Stone Axe");
    EXPECT_EQ(tool.GetExhibitCollection(), "Prehistoric Tools");
    EXPECT_EQ(tool.GetExhibitFoundationYear(), -3000);
}

TEST_F(AncientToolTest, NegativeFoundationYearTest) {
    tool.SetExhibitFoundationYear(-5000);
    EXPECT_EQ(tool.GetExhibitFoundationYear(), -5000);
}