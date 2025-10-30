//
// Created by user on 30.10.2025.
//

#ifndef LABWORK2_JEWERLY_H
#define LABWORK2_JEWERLY_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Jewelry : public Exhibit {
public:
    Jewelry() = default;
    ~Jewelry() = default;

    std::string GetJewelryMaterial() const;
    std::string GetJewelryGemstone() const;
    std::string GetJewelryType() const;
    double GetJewelryWeight() const;

    void SetJewelryMaterial(std::string material);
    void SetJewelryGemstone(std::string gemstone);
    void SetJewelryType(std::string type);
    void SetJewelryWeight(double weight);

    std::string GetExhibitType() const override;
private:
    std::string material_;
    std::string gemstone_;
    std::string jewelryType_;
    double weight_ = 0.0;
};

#endif //LABWORK2_JEWERLY_H