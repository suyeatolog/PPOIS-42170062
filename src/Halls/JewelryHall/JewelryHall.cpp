//
// Created by user on 30.10.2025.
//

#include "JewelryHall.h"
std::string JewelryHall::GetJewelryEra() const {
    return jewelryEra_;
}
void JewelryHall::SetJewelryEra(std::string era) {
    this->jewelryEra_ = era;
}
std::string JewelryHall::GetHallType() const {
    return "JewelryHall";
}