#include "Book.h"

std::string Book::GetAuthor() const {
    return Author_;
}
int Book::GetPageAmount() const {
    return pageAmount_;
}

void Book::SetAuthor(std::string author) {
    this->Author_ = author;
}
void Book::SetPageAmount(int pageAmount) {
    this->pageAmount_ = pageAmount;
}

std::string Book::GetExhibitType() const {
    return "Book";
}