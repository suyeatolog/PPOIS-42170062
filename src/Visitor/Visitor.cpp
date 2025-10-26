//
// Created by user on 25.10.2025.
//

#include "Visitor.h"

#include "../Exceptions/Exceptions.h"

std::string Visitor::GetVisitorName() const {
    return name_;
}
int Visitor::GetVisitorAge() const {
    return age_;
}
bool Visitor::GetVisitorHasTicket() const {
    return hasTicket_;
}

bool Visitor::GetVisitorHasAccess() const {
    return hasAccessToMuseum_;
}

void Visitor::SetVisitorName(std::string name) {
    if (name.empty()) {
        throw EmptyNameException("Visitor name cannot be empty.");
    }
    this->name_ = name;
}
void Visitor::SetVisitorAge(int age) {
    if (age < 0 || age > 150) {
        throw InvalidAgeException("Visitor age cannot be negative.");
    }
    this->age_ = age;
}
void Visitor::SetVisitorHasTicket(bool hasTicket) {
    this->hasTicket_ = hasTicket;
}
void Visitor::SetVisitorHasAccess(bool hasAccess) {
    this->hasAccessToMuseum_ = hasAccess;
}