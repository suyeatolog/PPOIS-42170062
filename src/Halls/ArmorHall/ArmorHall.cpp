//
// Created by user on 31.10.2025.
//

#include "ArmorHall.h"
std::string ArmorHall::GetArmorEra() const {
    return armorEra_;
}
void ArmorHall::SetArmorEra(std::string era) {
    this->armorEra_ = era;
}

std::string ArmorHall::GetHallType() const {
    return "ArmorHall";
}