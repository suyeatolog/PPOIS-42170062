#include <gtest/gtest.h>
#include "../WorldWarIIArtifact/WorldWarIIArtifact.h"

class WorldWarIIArtifactTest : public ::testing::Test {
protected:
    void SetUp() override {
        artifact.SetExhibitNumberId(7);
        artifact.SetExhibitName("M1 Garand Rifle");
        artifact.SetExhibitCollection("Military History");
        artifact.SetExhibitFoundationYear(1943);
        artifact.SetArtifactType("Weapon");
        artifact.SetCondition("Good");
        artifact.SetHasCombatHistory(true);
        artifact.SetOriginCountry("USA");
    }

    WorldWarIIArtifact artifact;
};

TEST_F(WorldWarIIArtifactTest, Inheritance) {
    EXPECT_EQ(artifact.GetExhibitType(), "World War II Artifact");
}

TEST_F(WorldWarIIArtifactTest, GettersTest) {
    EXPECT_EQ(artifact.GetArtifactType(), "Weapon");
    EXPECT_EQ(artifact.GetCondition(), "Good");
    EXPECT_TRUE(artifact.GetHasCombatHistory());
    EXPECT_EQ(artifact.GetOriginCountry(), "USA");
}

TEST_F(WorldWarIIArtifactTest, SettersTest) {
    artifact.SetArtifactType("Uniform");
    artifact.SetCondition("Excellent");
    artifact.SetHasCombatHistory(false);
    artifact.SetOriginCountry("Germany");

    EXPECT_EQ(artifact.GetArtifactType(), "Uniform");
    EXPECT_EQ(artifact.GetCondition(), "Excellent");
    EXPECT_FALSE(artifact.GetHasCombatHistory());
    EXPECT_EQ(artifact.GetOriginCountry(), "Germany");
}

TEST_F(WorldWarIIArtifactTest, ConstructorTest) {
    WorldWarIIArtifact defaultArtifact;

    EXPECT_EQ(defaultArtifact.GetArtifactType(), "");
    EXPECT_EQ(defaultArtifact.GetCondition(), "");
    EXPECT_FALSE(defaultArtifact.GetHasCombatHistory());
    EXPECT_EQ(defaultArtifact.GetOriginCountry(), "");
}

TEST_F(WorldWarIIArtifactTest, AsExhibitTest) {
    EXPECT_EQ(artifact.GetExhibitNumberId(), 7);
    EXPECT_EQ(artifact.GetExhibitName(), "M1 Garand Rifle");
    EXPECT_EQ(artifact.GetExhibitCollection(), "Military History");
    EXPECT_EQ(artifact.GetExhibitFoundationYear(), 1943);
}