//
// Created by user on 29.10.2025.
//

#include "ArchaeologicalHall.h"
std::string ArchaeologicalHall::GetArchaeologicalEra() const {
    return archaeologicalEra_;
}
void ArchaeologicalHall::SetArchaeologicalEra(std::string era) {
    this->archaeologicalEra_ = era;
}
std::string ArchaeologicalHall::GetHallType() const {
    return "ArchaeologicalHall";
}