//
// Created by user on 22.10.2025.
//

#include "Exhibition.h"

std::string Exhibition::GetExhibitionName() const {
    return exhibitionName_;
}
std::string Exhibition::GetExhibitionTheme() const {
    return theme_;
}
std::vector<Exhibit*> Exhibition::GetExhibits() const {
    return exhibits_;
}
int Exhibition::GetExhibitsCount() const {
    return exhibits_.size();
}

Exhibit* Exhibition::GetExhibitByIndex(int index) const {
    if (index >= 0 && index < exhibits_.size()) {
        return exhibits_[index];
    }
    return nullptr;
}
void Exhibition::SetExhibitionName(std::string exhibitionName) {
    this->exhibitionName_ = exhibitionName;
}
void Exhibition::SetTheme(std::string theme) {
    this->theme_ = theme;
}
void Exhibition::AddExhibit(Exhibit* exhibit) {
    this->exhibits_.push_back(exhibit);
}
void Exhibition::RemoveExhibit(int index) {
    if (index >= 0 && index < exhibits_.size()) {
        exhibits_.erase(exhibits_.begin() + index);
    }
}
