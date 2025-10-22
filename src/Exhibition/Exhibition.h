//
// Created by user on 22.10.2025.
//

#ifndef LABWORK2_EXHIBITION_H
#define LABWORK2_EXHIBITION_H
#include <string>
#include <vector>

#include "../Exhibit/Exhibit.h"

class Exhibition {
public:
    Exhibition() = default;
    ~Exhibition() = default;

    std::string GetExhibitionName() const;
    std::string GetExhibitionTheme() const;
    std::vector<Exhibit*> GetExhibits() const;
    int GetExhibitsCount() const;
    Exhibit* GetExhibitByIndex(int index) const;

    void SetExhibitionName(std::string exhibitionName);
    void SetTheme(std::string theme);
    void AddExhibit(Exhibit* exhibit);
    void RemoveExhibit(int index);
private:
    std::string exhibitionName_;
    std::string theme_;
    std::vector<Exhibit*> exhibits_;
};

#endif //LABWORK2_EXHIBITION_H