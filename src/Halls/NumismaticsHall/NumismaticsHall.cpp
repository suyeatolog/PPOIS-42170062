//
// Created by user on 29.10.2025.
//

#include "NumismaticsHall.h"
std::string NumismaticsHall::GetCoinEra() const {
    return coinEra_;
}
void NumismaticsHall::SetCoinEra(std::string coinEra) {
    this->coinEra_ = coinEra;
}
std::string NumismaticsHall::GetHallType() const {
    return "NumismaticsHall";
}