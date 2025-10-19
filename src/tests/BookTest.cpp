#include <gtest/gtest.h>
#include "../Book/Book.h"

class BookTest : public ::testing::Test {
protected:
    void SetUp() override {
        book.SetExhibitNumberId(5);
        book.SetExhibitName("First Folio");
        book.SetExhibitCollection("Rare Books");
        book.SetExhibitFoundationYear(1623);
        book.SetAuthor("William Shakespeare");
        book.SetPageAmount(900);
    }

    Book book;
};

TEST_F(BookTest, Inheritance) {
    EXPECT_EQ(book.GetExhibitType(), "Book");
}

TEST_F(BookTest, GettersTest) {
    EXPECT_EQ(book.GetAuthor(), "William Shakespeare");
    EXPECT_EQ(book.GetPageAmount(), 900);
}

TEST_F(BookTest, SettersTest) {
    book.SetAuthor("Charles Dickens");
    book.SetPageAmount(350);

    EXPECT_EQ(book.GetAuthor(), "Charles Dickens");
    EXPECT_EQ(book.GetPageAmount(), 350);
}

TEST_F(BookTest, ConstructorTest) {
    Book defaultBook;

    EXPECT_EQ(defaultBook.GetAuthor(), "");
    EXPECT_EQ(defaultBook.GetPageAmount(), 0);
}

TEST_F(BookTest, AsExhibitTest) {
    EXPECT_EQ(book.GetExhibitNumberId(), 5);
    EXPECT_EQ(book.GetExhibitName(), "First Folio");
    EXPECT_EQ(book.GetExhibitCollection(), "Rare Books");
    EXPECT_EQ(book.GetExhibitFoundationYear(), 1623);
}