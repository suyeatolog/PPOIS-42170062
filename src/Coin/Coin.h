#ifndef LABWORK2_COIN_H
#define LABWORK2_COIN_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Coin : public Exhibit {
public:
    Coin() = default;

    std::string GetMetal() const;
    std::string GetCurrency() const;
    int GetDenomination() const;
    int GetMintYear() const;
    std::string GetCondition() const;
    double GetWeight() const;
    double GetDiameter() const;

    void SetMetal(std::string metal);
    void SetCurrency(std::string currency);
    void SetDenomination(int denomination);
    void SetMintYear(int year);
    void SetCondition(std::string condition);
    void SetWeight(double weight);
    void SetDiameter(double diameter);

    std::string GetExhibitType() const override;

private:
    std::string metal_;
    std::string currency_;
    int denomination_ = 0;
    int mintYear_ = 0;
    std::string condition_;
    double weight_ = 0.0;
    double diameter_ = 0.0;
};

#endif //LABWORK2_COIN_H