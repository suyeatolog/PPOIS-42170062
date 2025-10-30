//
// Created by user on 30.10.2025.
//

#ifndef LABWORK2_COSTUME_H
#define LABWORK2_COSTUME_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Costume : public Exhibit {
public:
    Costume() = default;
    ~Costume() = default;

    std::string GetCostumeType() const;
    std::string GetFabric() const;
    std::string GetGender() const;
    int GetSize() const;

    void SetCostumeType(std::string costumeType);
    void SetFabric(std::string fabric);
    void SetGender(std::string gender);
    void SetSize(int size);

    std::string GetExhibitType() const override;
private:
    std::string costumeType_;
    std::string fabric_;
    std::string gender_;
    int size_ = 0;
};
#endif //LABWORK2_COSTUME_H