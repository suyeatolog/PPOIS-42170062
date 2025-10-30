//
// Created by user on 30.10.2025.
//

#ifndef LABWORK2_JEWELRYHALL_H
#define LABWORK2_JEWELRYHALL_H
#include "../Hall.h"
#include <string>

class JewelryHall : public Hall {
    public:
    JewelryHall() = default;
    ~JewelryHall() = default;

    std::string GetJewelryEra() const;
    void SetJewelryEra(std::string era);

    std::string GetHallType() const override;
private:
    std::string jewelryEra_;
};

#endif //LABWORK2_JEWELRYHALL_H