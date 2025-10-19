#include "Coin.h"

std::string Coin::GetMetal() const {
    return metal_;
}
std::string Coin::GetCurrency() const {
    return currency_;
}
int Coin::GetDenomination() const {
    return denomination_;
}
int Coin::GetMintYear() const {
    return mintYear_;
}
std::string Coin::GetCondition() const {
    return condition_;
}
double Coin::GetWeight() const {
    return weight_;
}
double Coin::GetDiameter() const {
    return diameter_;
}

void Coin::SetMetal(std::string metal) {
    this->metal_ = metal;
}
void Coin::SetCurrency(std::string currency) {
    this->currency_ = currency;
}
void Coin::SetDenomination(int denomination) {
    this->denomination_ = denomination;
}
void Coin::SetMintYear(int year) {
    this->mintYear_ = year;
}
void Coin::SetCondition(std::string condition) {
    this->condition_ = condition;
}
void Coin::SetWeight(double weight) {
    this->weight_ = weight;
}
void Coin::SetDiameter(double diameter) {
    this->diameter_ = diameter;
}

std::string Coin::GetExhibitType() const {
    return "Coin";
}