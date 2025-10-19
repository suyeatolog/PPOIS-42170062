#include <gtest/gtest.h>
#include "../Painting/Painting.h"

class PaintingTest : public ::testing::Test {
    protected:
    void SetUp() override {
        painting.SetExhibitNumberId(1);
        painting.SetExhibitName("Starry Night");
        painting.SetExhibitCollection("Modern Art");
        painting.SetExhibitFoundationYear(1889);
        painting.SetArtist("Vincent van Gogh");
        painting.SetStyle("Post-Impressionism");
        painting.SetMaterial("Oil on canvas");
        painting.SetLength(74);
        painting.SetWidth(92);
    }

    Painting painting;
};

TEST_F(PaintingTest, Inheritance) {
    EXPECT_EQ(painting.GetExhibitType(), "Painting");
}

TEST_F(PaintingTest, ConstructorTest) {
    Painting defaultPainting;

    EXPECT_EQ(defaultPainting.GetArtist(), "");
    EXPECT_EQ(defaultPainting.GetStyle(), "");
    EXPECT_EQ(defaultPainting.GetMaterial(), "");
    EXPECT_EQ(defaultPainting.GetLength(), 0);
    EXPECT_EQ(defaultPainting.GetWidth(), 0);
}

TEST_F(PaintingTest, GettersTest) {
    EXPECT_EQ(painting.GetArtist(), "Vincent van Gogh");
    EXPECT_EQ(painting.GetStyle(), "Post-Impressionism");
    EXPECT_EQ(painting.GetMaterial(), "Oil on canvas");
    EXPECT_EQ(painting.GetLength(), 74);
    EXPECT_EQ(painting.GetWidth(), 92);
}

TEST_F(PaintingTest, SettersTest) {
    painting.SetArtist("Pablo Picasso");
    painting.SetStyle("Cubism");
    painting.SetMaterial("Acrylic on canvas");
    painting.SetLength(100);
    painting.SetWidth(80);

    EXPECT_EQ(painting.GetArtist(), "Pablo Picasso");
    EXPECT_EQ(painting.GetStyle(), "Cubism");
    EXPECT_EQ(painting.GetMaterial(), "Acrylic on canvas");
    EXPECT_EQ(painting.GetLength(), 100);
    EXPECT_EQ(painting.GetWidth(), 80);
}
TEST_F(PaintingTest, AsExhibitTest) {
    EXPECT_EQ(painting.GetExhibitNumberId(), 1);
    EXPECT_EQ(painting.GetExhibitName(), "Starry Night");
    EXPECT_EQ(painting.GetExhibitCollection(), "Modern Art");
    EXPECT_EQ(painting.GetExhibitFoundationYear(), 1889);
}