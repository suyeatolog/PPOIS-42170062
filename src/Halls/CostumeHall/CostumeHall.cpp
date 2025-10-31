//
// Created by user on 31.10.2025.
//

#include "CostumeHall.h"
std::string CostumeHall::GetCostumeEra() const {
    return costumeEra_;
}
void CostumeHall::SetCostumeEra(std::string era) {
    this->costumeEra_ = era;
}
std::string CostumeHall::GetHallType() const {
    return "CostumeHall";
}