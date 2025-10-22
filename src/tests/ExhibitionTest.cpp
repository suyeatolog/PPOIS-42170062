#include <gtest/gtest.h>
#include "../Exhibition/Exhibition.h"
#include "../Painting/Painting.h"
#include "../Sculpture/Sculpture.h"
#include "../Coin/Coin.h"
#include "../CeramicVase/CeramicVase.h"

class ExhibitionTest : public ::testing::Test {
    protected:

    void SetUp() override {
        exhibition.SetExhibitionName("Masterpieces Collection");
        exhibition.SetTheme("Art Through Ages");

        painting.SetExhibitNumberId(1);
        painting.SetExhibitName("Mona Lisa");

        sculpture.SetExhibitNumberId(2);
        sculpture.SetExhibitName("David");

        coin.SetExhibitNumberId(3);
        coin.SetExhibitName("Ancient Roman Coin");

        vase.SetExhibitNumberId(4);
        vase.SetExhibitName("Ming Dynasty Vase");
    }
    Exhibition exhibition;
    Painting painting;
    Sculpture sculpture;
    Coin coin;
    CeramicVase vase;
};

TEST_F(ExhibitionTest, GettersTest) {
    EXPECT_EQ(exhibition.GetExhibitionName(), "Masterpieces Collection");
    EXPECT_EQ(exhibition.GetExhibitionTheme(), "Art Through Ages");
    EXPECT_EQ(exhibition.GetExhibitsCount(), 0);
    EXPECT_TRUE(exhibition.GetExhibits().empty());
}

TEST_F(ExhibitionTest, AddSingleExhibitTest) {
    exhibition.AddExhibit(&painting);

    EXPECT_EQ(exhibition.GetExhibitsCount(), 1);

    auto exhibits = exhibition.GetExhibits();
    EXPECT_EQ(exhibits.size(), 1);
    EXPECT_EQ(exhibits[0]->GetExhibitName(), "Mona Lisa");
    EXPECT_EQ(exhibits[0]->GetExhibitNumberId(), 1);
}

TEST_F(ExhibitionTest, AddMultipleExhibitsTest) {
    exhibition.AddExhibit(&painting);
    exhibition.AddExhibit(&sculpture);
    exhibition.AddExhibit(&coin);
    exhibition.AddExhibit(&vase);

    EXPECT_EQ(exhibition.GetExhibitsCount(), 4);

    auto exhibits = exhibition.GetExhibits();
    EXPECT_EQ(exhibits[0]->GetExhibitName(), "Mona Lisa");
    EXPECT_EQ(exhibits[0]->GetExhibitNumberId(), 1);
    EXPECT_EQ(exhibits[1]->GetExhibitName(), "David");
    EXPECT_EQ(exhibits[1]->GetExhibitNumberId(), 2);
    EXPECT_EQ(exhibits[2]->GetExhibitName(), "Ancient Roman Coin");
    EXPECT_EQ(exhibits[2]->GetExhibitNumberId(), 3);
    EXPECT_EQ(exhibits[3]->GetExhibitName(), "Ming Dynasty Vase");
    EXPECT_EQ(exhibits[3]->GetExhibitNumberId(), 4);
}
TEST_F(ExhibitionTest, GetExhibitByIndexTest) {
    exhibition.AddExhibit(&painting);
    exhibition.AddExhibit(&sculpture);
    exhibition.AddExhibit(&coin);

    Exhibit* first = exhibition.GetExhibitByIndex(0);
    Exhibit* second = exhibition.GetExhibitByIndex(1);
    Exhibit* third = exhibition.GetExhibitByIndex(2);

    EXPECT_NE(first, nullptr);
    EXPECT_NE(second, nullptr);
    EXPECT_NE(third, nullptr);
    EXPECT_EQ(first->GetExhibitName(), "Mona Lisa");
    EXPECT_EQ(second->GetExhibitName(), "David");
    EXPECT_EQ(third->GetExhibitName(), "Ancient Roman Coin");


    Exhibit* negativeIndex = exhibition.GetExhibitByIndex(-1);
    Exhibit* tooLargeIndex = exhibition.GetExhibitByIndex(10);

    EXPECT_EQ(negativeIndex, nullptr);
    EXPECT_EQ(tooLargeIndex, nullptr);
}

TEST_F(ExhibitionTest, RemoveExhibitByIndex) {
    exhibition.AddExhibit(&painting);
    exhibition.AddExhibit(&sculpture);
    exhibition.AddExhibit(&coin);
    exhibition.AddExhibit(&vase);

    EXPECT_EQ(exhibition.GetExhibitsCount(), 4);

    exhibition.RemoveExhibit(1);
    EXPECT_EQ(exhibition.GetExhibitsCount(), 3);

    auto exhibits = exhibition.GetExhibits();
    EXPECT_EQ(exhibits[0]->GetExhibitName(), "Mona Lisa");
    EXPECT_EQ(exhibits[1]->GetExhibitName(), "Ancient Roman Coin");
    EXPECT_EQ(exhibits[2]->GetExhibitName(), "Ming Dynasty Vase");

    exhibition.RemoveExhibit(0);
    EXPECT_EQ(exhibition.GetExhibitsCount(), 2);
    EXPECT_EQ(exhibition.GetExhibits()[0]->GetExhibitName(), "Ancient Roman Coin");

    exhibition.RemoveExhibit(1);
    EXPECT_EQ(exhibition.GetExhibitsCount(), 1);
    EXPECT_EQ(exhibition.GetExhibits()[0]->GetExhibitName(), "Ancient Roman Coin");
}
TEST_F(ExhibitionTest, RemoveInvalidIndexTest) {
    exhibition.AddExhibit(&painting);

    exhibition.RemoveExhibit(-1);
    exhibition.RemoveExhibit(5);

    EXPECT_EQ(exhibition.GetExhibitsCount(), 1);
}