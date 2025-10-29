//
// Created by user on 29.10.2025.
//

#ifndef LABWORK2_WARHALL_H
#define LABWORK2_WARHALL_H
#include "../Hall.h"
#include <string>

class WarHall : public Hall {
public:
    WarHall() = default;
    ~WarHall() = default;

    std::string GetWarName() const;
    void SetWarName(std::string name);

    std::string GetHallType() const override;
private:
    std::string warName_;
};

#endif //LABWORK2_WARHALL_H