//
// Created by user on 16.10.2025.
//
#include "Exhibit.h"
#include <iostream>
#include <string>

std::string Exhibit::GetExhibitCollection() const {
    return collection_;
}

std::string Exhibit::GetExhibitName() const {
    return name_;
}

int Exhibit::GetExhibitNumberId() const {
    return numberId_;
}

int Exhibit::GetExhibitFoundationYear() const {
    return foundationYear_;
}

void Exhibit::SetExhibitCollection(std::string collection) {
    this->collection_ = collection;
}
void Exhibit::SetExhibitName(std::string name) {
    this->name_ = name;
}
void Exhibit::SetExhibitNumberId(int number) {
    this->numberId_ = number;
}

void Exhibit::SetExhibitFoundationYear(int number) {
    this->foundationYear_ = number;
}