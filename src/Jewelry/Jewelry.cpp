//
// Created by user on 30.10.2025.
//

#include "Jewelry.h"
std::string Jewelry::GetJewelryMaterial() const {
    return material_;
}
std::string Jewelry::GetJewelryGemstone() const {
    return gemstone_;
}
std::string Jewelry::GetJewelryType() const {
    return jewelryType_;
}
double Jewelry::GetJewelryWeight() const {
    return weight_;
}

void Jewelry::SetJewelryMaterial(std::string material) {
    this->material_ = material;
}
void Jewelry::SetJewelryGemstone(std::string gemstone) {
    this->gemstone_ = gemstone;
}
void Jewelry::SetJewelryType(std::string type) {
    this->jewelryType_ = type;
}
void Jewelry::SetJewelryWeight(double weight) {
    this->weight_ = weight;
}

std::string Jewelry::GetExhibitType() const {
    return "Jewelry";
}