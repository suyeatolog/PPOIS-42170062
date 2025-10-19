//
// Created by user on 17.10.2025.
//
#include "gtest/gtest.h"
#include "../Fossil/Fossil.h"
class FossilTest : public ::testing::Test {
protected:
    void SetUp() override {
        fossil.SetSpecies("Terminocavus sealeyi");
        fossil.SetExhibitNumberId(3);
        fossil.SetExhibitName("Terminocavus");
        fossil.SetExhibitCollection("bird-like dinosaurs");
        fossil.SetExhibitFoundationYear(1867);
        fossil.SetFoundationPlace("Africa");
        fossil.SetWeight(3572.5);
        fossil.SetBoneAmount(213);
        fossil.SetLength(200);
        fossil.SetWidth(100);
        fossil.SetHeight(300);
    }

    Fossil fossil;
};

TEST_F(FossilTest, Inheritance) {
    EXPECT_EQ(fossil.GetExhibitType(), "Fossil");
}
TEST_F(FossilTest, ConstructorTest) {
    Fossil defaultFossil;
    EXPECT_EQ(defaultFossil.GetSpecies(),"");
    EXPECT_EQ(defaultFossil.GetFoundationPlace(), "");
    EXPECT_EQ(defaultFossil.GetBoneAmount(), 0);
    EXPECT_EQ(defaultFossil.GetWeight(), 0.0);
    EXPECT_EQ(defaultFossil.GetLength(), 0);
    EXPECT_EQ(defaultFossil.GetWidth(), 0);
    EXPECT_EQ(defaultFossil.GetHeight(), 0);
}
TEST_F(FossilTest, GettersTest) {
    EXPECT_EQ(fossil.GetSpecies(),"Terminocavus sealeyi");
    EXPECT_EQ(fossil.GetFoundationPlace(), "Africa");
    EXPECT_EQ(fossil.GetBoneAmount(), 213);
    EXPECT_EQ(fossil.GetWeight(), 3572.5);
    EXPECT_EQ(fossil.GetLength(), 200);
    EXPECT_EQ(fossil.GetWidth(), 100);
    EXPECT_EQ(fossil.GetHeight(), 300);
}
TEST_F(FossilTest, SettersTest) {
    fossil.SetSpecies("Huayracursor");
    fossil.SetFoundationPlace("Eurasia");
    fossil.SetBoneAmount(500);
    fossil.SetWeight(6000.1);
    fossil.SetLength(250);
    fossil.SetWidth(150);
    fossil.SetHeight(200);

    EXPECT_EQ(fossil.GetSpecies(),"Huayracursor");
    EXPECT_EQ(fossil.GetFoundationPlace(), "Eurasia");
    EXPECT_EQ(fossil.GetBoneAmount(), 500);
    EXPECT_EQ(fossil.GetWeight(), 6000.1);
    EXPECT_EQ(fossil.GetLength(), 250);
    EXPECT_EQ(fossil.GetWidth(), 150);
    EXPECT_EQ(fossil.GetHeight(), 200);
}

TEST_F(FossilTest, AsExhibitTest) {
    EXPECT_EQ(fossil.GetExhibitNumberId(), 3);
    EXPECT_EQ(fossil.GetExhibitName(), "Terminocavus");
    EXPECT_EQ(fossil.GetExhibitCollection(), "bird-like dinosaurs");
    EXPECT_EQ(fossil.GetExhibitFoundationYear(), 1867);
}