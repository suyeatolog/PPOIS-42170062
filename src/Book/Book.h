//
// Created by user on 17.10.2025.
//

#ifndef LABWORK2_BOOK_H
#define LABWORK2_BOOK_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Book : public Exhibit {
public:
    Book() = default;

    std::string GetAuthor() const;
    int GetPageAmount() const;

    void SetAuthor(std::string author);
    void SetPageAmount(int pageAmount);

    std::string GetExhibitType() const override;

private:
    std::string Author_;
    int pageAmount_ = 0;
};

#endif //LABWORK2_BOOK_H