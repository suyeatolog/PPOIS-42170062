//
// Created by user on 29.10.2025.
//

#include "CeramicHall.h"
std::string CeramicHall::GetVaseEra() const {
    return vaseEra_;
}
void CeramicHall::SetVaseEra(std::string era) {
    this->vaseEra_ = era;
}
std::string CeramicHall::GetHallType() const {
    return "CeramicHall";
}