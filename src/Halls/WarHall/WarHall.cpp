//
// Created by user on 29.10.2025.
//

#include "WarHall.h"
std::string WarHall::GetWarName() const {
    return warName_;
}
void WarHall::SetWarName(std::string name) {
    this->warName_ = name;
}

std::string WarHall::GetHallType() const {
    return "WarHall";
}