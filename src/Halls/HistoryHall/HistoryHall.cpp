//
// Created by user on 27.10.2025.
//

#include "HistoryHall.h"
std::string HistoryHall::GetHistoricalPeriod() const {
    return HistoricalPeriod_;
}
void HistoryHall::SetHistoricalPeriod(std::string HistoricalPeriod) {
    this->HistoricalPeriod_ = HistoricalPeriod;
}

std::string HistoryHall::GetHallType() const {
    return "HistoryHall";
}