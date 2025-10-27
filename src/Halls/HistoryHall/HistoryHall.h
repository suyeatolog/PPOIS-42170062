#ifndef LABWORK2_HISTORYHALL_H
#define LABWORK2_HISTORYHALL_H
#include "../Hall.h"
#include <iostream>

class HistoryHall : public Hall {
    public:
    HistoryHall() = default;

    std::string GetHistoricalPeriod() const;

    void SetHistoricalPeriod(std::string historicalPeriod);

    std::string GetHallType() const override;
private:
    std::string HistoricalPeriod_;
};

#endif //LABWORK2_HISTORYHALL_H