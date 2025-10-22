//
// Created by user on 22.10.2025.
//

#include "Hall.h"

std::string Hall::GetHallName() const {
    return hallName_;
}
int Hall::GetHallNumber() const {
    return hallNumber_;
}
double Hall::GetHallArea() const {
    return area_;
}
int Hall::GetHallCapacity() const {
    return capacity_;
}

void Hall::SetHallName(std::string hallName) {
    this->hallName_ = hallName;
}
void Hall::SetHallNumber(int hallNumber) {
    this->hallNumber_ = hallNumber;
}
void Hall::SetHallArea(double area) {
    this->area_ = area;
}
void Hall::SetHallCapacity(int capacity) {
    this->capacity_ = capacity;
}

void Hall::SetCurrentExhibition(Exhibition *exhibition) {
    this->currentExhibition_ = exhibition;
}
Exhibition* Hall::GetCurrentExhibition() const {
    return currentExhibition_;
}
bool Hall::HasExhibition() const {
    return currentExhibition_ != nullptr;
}