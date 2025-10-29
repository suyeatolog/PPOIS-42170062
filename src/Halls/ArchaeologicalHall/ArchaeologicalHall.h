//
// Created by user on 29.10.2025.
//

#ifndef LABWORK2_ARCHAEOLOGICALHALL_H
#define LABWORK2_ARCHAEOLOGICALHALL_H
#include "../Hall.h"
#include <string>

class ArchaeologicalHall : public Hall {
    public:
    ArchaeologicalHall() = default;
    ~ArchaeologicalHall() = default;

    std::string GetArchaeologicalEra() const;
    void SetArchaeologicalEra(std::string era);

    std::string GetHallType() const override;
private:
    std::string archaeologicalEra_;
};

#endif //LABWORK2_ARCHAEOLOGICALHALL_H