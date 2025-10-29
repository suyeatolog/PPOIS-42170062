//
// Created by user on 29.10.2025.
//

#ifndef LABWORK2_CERAMICHALL_H
#define LABWORK2_CERAMICHALL_H
#include "../Hall.h"
#include <string>

class CeramicHall : public Hall {
public:
    CeramicHall() = default;
    ~CeramicHall() = default;

    std::string GetVaseEra() const;
    void SetVaseEra(std::string era);

    std::string GetHallType() const override;
private:
    std::string vaseEra_;
};

#endif //LABWORK2_CERAMICHALL_H