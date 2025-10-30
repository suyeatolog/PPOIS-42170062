//
// Created by user on 30.10.2025.
//

#include "Armor.h"
std::string Armor::GetArmorMaterial() const {
    return material_;
}
std::string Armor::GetArmorType() const {
    return armorType_;
}
bool Armor::GetArmorIsFunctional() const {
    return isFunctional_;
}
double Armor::GetJewelryWeight() const {
    return weight_;
}

void Armor::SetArmorMaterial(std::string material) {
    this->material_ = material;
}
void Armor::SetArmorType(std::string type) {
    this->armorType_ = type;
}
void Armor::SetArmorIsFunctional(bool isFunctional) {
    this->isFunctional_ = isFunctional;
}
void Armor::SetJewelryWeight(double weight) {
    this->weight_ = weight;
}

std::string Armor::GetExhibitType() const {
    return "Armor";
}