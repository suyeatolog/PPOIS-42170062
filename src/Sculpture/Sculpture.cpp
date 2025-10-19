//
// Created by user on 16.10.2025.
//

#include "Sculpture.h"
std::string Sculpture::GetSculpturist() const {
    return sculpturist_;
}
std::string Sculpture::GetMaterial() const {
    return material_;
}
double Sculpture::GetWeight() const {
    return weight_;
}
bool Sculpture::IsFragile() const {
    return isFragile_;
}
int Sculpture::GetLength() const {
    return length_;
}
int Sculpture::GetWidth() const {
    return width_;
}
int Sculpture::GetHeight() const {
    return height_;
}

void Sculpture::SetSculpturist(std::string sculpturist) {
    this->sculpturist_ = sculpturist;
}
void Sculpture::SetMaterial(std::string material) {
    this->material_ = material;
}
void Sculpture::SetWeight(double weight) {
    this->weight_ = weight;
}
void Sculpture::SetFragile(bool isFragile) {
    this->isFragile_ = isFragile;
}
void Sculpture::SetLength(int length) {
    this->length_ = length;
}
void Sculpture::SetWidth(int width) {
    this->width_ = width;
}
void Sculpture::SetHeight(int height) {
    this->height_ = height;
}

std::string Sculpture::GetExhibitType() const {
    return "Sculpture";
}