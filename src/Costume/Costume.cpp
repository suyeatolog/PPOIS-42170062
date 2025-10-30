//
// Created by user on 30.10.2025.
//

#include "Costume.h"
std::string Costume::GetCostumeType() const {
    return costumeType_;
}
std::string Costume::GetFabric() const {
    return fabric_;
}
std::string Costume::GetGender() const {
    return gender_;
}
int Costume::GetSize() const {
    return size_;
}

void Costume::SetCostumeType(std::string costumeType) {
    this->costumeType_ = costumeType;
}
void Costume::SetFabric(std::string fabric) {
    this->fabric_ = fabric;
}
void Costume::SetGender(std::string gender) {
    this->gender_ = gender;
}
void Costume::SetSize(int size) {
    this->size_ = size;
}
std::string Costume::GetExhibitType() const {
    return "Costume";
}
