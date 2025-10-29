//
// Created by user on 29.10.2025.
//

#ifndef LABWORK2_NUMISMATICSHALL_H
#define LABWORK2_NUMISMATICSHALL_H
#include "../Hall.h"
#include <string>

class NumismaticsHall : public Hall {
public:
    NumismaticsHall() = default;
    ~NumismaticsHall() = default;

    std::string GetCoinEra() const;
    void SetCoinEra(std::string coinEra);

    std::string GetHallType() const override;
private:
    std::string coinEra_;
};

#endif //LABWORK2_NUMISMATICSHALL_H