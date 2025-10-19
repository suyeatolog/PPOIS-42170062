#include <gtest/gtest.h>
#include "../Coin/Coin.h"

class CoinTest : public ::testing::Test {
protected:
    void SetUp() override {
        coin.SetExhibitNumberId(9);
        coin.SetExhibitName("Imperial Gold Coin");
        coin.SetExhibitCollection("Numismatics");
        coin.SetExhibitFoundationYear(1897);
        coin.SetMetal("Gold");
        coin.SetCurrency("Ruble");
        coin.SetDenomination(10);
        coin.SetMintYear(1897);
        coin.SetCondition("Extremely Fine");
        coin.SetWeight(12.9);
        coin.SetDiameter(24.6);
    }

    Coin coin;
};

TEST_F(CoinTest, Inheritance) {
    EXPECT_EQ(coin.GetExhibitType(), "Coin");
}

TEST_F(CoinTest, GettersTest) {
    EXPECT_EQ(coin.GetMetal(), "Gold");
    EXPECT_EQ(coin.GetCurrency(), "Ruble");
    EXPECT_EQ(coin.GetDenomination(), 10);
    EXPECT_EQ(coin.GetMintYear(), 1897);
    EXPECT_EQ(coin.GetCondition(), "Extremely Fine");
    EXPECT_DOUBLE_EQ(coin.GetWeight(), 12.9);
    EXPECT_DOUBLE_EQ(coin.GetDiameter(), 24.6);
}

TEST_F(CoinTest, SettersTest) {
    coin.SetMetal("Silver");
    coin.SetCurrency("Dollar");
    coin.SetDenomination(1);
    coin.SetMintYear(1921);
    coin.SetCondition("Uncirculated");
    coin.SetWeight(26.73);
    coin.SetDiameter(38.1);

    EXPECT_EQ(coin.GetMetal(), "Silver");
    EXPECT_EQ(coin.GetCurrency(), "Dollar");
    EXPECT_EQ(coin.GetDenomination(), 1);
    EXPECT_EQ(coin.GetMintYear(), 1921);
    EXPECT_EQ(coin.GetCondition(), "Uncirculated");
    EXPECT_DOUBLE_EQ(coin.GetWeight(), 26.73);
    EXPECT_DOUBLE_EQ(coin.GetDiameter(), 38.1);
}

TEST_F(CoinTest, ConstructorTest) {
    Coin defaultCoin;

    EXPECT_EQ(defaultCoin.GetMetal(), "");
    EXPECT_EQ(defaultCoin.GetCurrency(), "");
    EXPECT_EQ(defaultCoin.GetDenomination(), 0);
    EXPECT_EQ(defaultCoin.GetMintYear(), 0);
    EXPECT_EQ(defaultCoin.GetCondition(), "");
    EXPECT_DOUBLE_EQ(defaultCoin.GetWeight(), 0.0);
    EXPECT_DOUBLE_EQ(defaultCoin.GetDiameter(), 0.0);
}

TEST_F(CoinTest, AsExhibitTest) {
    EXPECT_EQ(coin.GetExhibitNumberId(), 9);
    EXPECT_EQ(coin.GetExhibitName(), "Imperial Gold Coin");
    EXPECT_EQ(coin.GetExhibitCollection(), "Numismatics");
    EXPECT_EQ(coin.GetExhibitFoundationYear(), 1897);
}