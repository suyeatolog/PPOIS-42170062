//
// Created by user on 31.10.2025.
//

#ifndef LABWORK2_ARMORHALL_H
#define LABWORK2_ARMORHALL_H
#include "../Hall.h"
#include <string>

class ArmorHall : public Hall {
    public:
    ArmorHall() = default;
    ~ArmorHall() = default;

    std::string GetArmorEra() const;
    void SetArmorEra(std::string era);

    std::string GetHallType() const override;
    private:
    std::string armorEra_;
};

#endif //LABWORK2_ARMORHALL_H