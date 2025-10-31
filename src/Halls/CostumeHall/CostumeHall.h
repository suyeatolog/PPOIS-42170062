//
// Created by user on 31.10.2025.
//

#ifndef LABWORK2_COSTUMEHALL_H
#define LABWORK2_COSTUMEHALL_H
#include "../Hall.h"
#include <string>

class CostumeHall : public Hall {
    public:
    CostumeHall() = default;
    ~CostumeHall() = default;

    std::string GetCostumeEra() const;
    void SetCostumeEra(std::string era);

    std::string GetHallType() const;
private:
    std::string costumeEra_;
};

#endif //LABWORK2_COSTUMEHALL_H