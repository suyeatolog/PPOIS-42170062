//
// Created by user on 30.10.2025.
//

#ifndef LABWORK2_ARMOR_H
#define LABWORK2_ARMOR_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Armor : public Exhibit {
public:
    Armor() = default;
    ~Armor() = default;

    std::string GetArmorMaterial() const;
    std::string GetArmorType() const;
    bool GetArmorIsFunctional() const;
    double GetJewelryWeight() const;

    void SetArmorMaterial(std::string material);
    void SetArmorType(std::string type);
    void SetArmorIsFunctional(bool isFunctional);
    void SetJewelryWeight(double weight);

    std::string GetExhibitType() const override;
private:
    std::string material_;
    std::string armorType_;
    double weight_ = 0.0;
    bool isFunctional_ = false;
};

#endif //LABWORK2_ARMOR_H