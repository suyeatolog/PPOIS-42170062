#include "Fossil.h"
std::string Fossil::GetSpecies() const {
    return species_;
}
std::string Fossil::GetFoundationPlace() const {
    return foundationPlace_;
}
int Fossil::GetBoneAmount() const {
    return boneAmount_;
}
double Fossil::GetWeight() const {
    return weight_;
}
int Fossil::GetLength() const {
    return length_;
}
int Fossil::GetWidth() const {
    return width_;
}
int Fossil::GetHeight() const {
    return height_;
}

void Fossil::SetSpecies(std::string species) {
    this->species_ = species;
}
void Fossil::SetFoundationPlace(std::string foundationPlace) {
    this->foundationPlace_ = foundationPlace;
}
void Fossil::SetBoneAmount(int boneAmount) {
    this->boneAmount_ = boneAmount;
}
void Fossil::SetWeight(double weight) {
    this->weight_ = weight;
}
void Fossil::SetLength(int length) {
    this->length_ = length;
}
void Fossil::SetWidth(int width) {
    this->width_ = width;
}
void Fossil::SetHeight(int height) {
    this->height_ = height;
}

std::string Fossil::GetExhibitType() const {
    return "Fossil";
}