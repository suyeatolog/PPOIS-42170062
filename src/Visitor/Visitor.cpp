//
// Created by user on 25.10.2025.
//

#include "Visitor.h"
std::string Visitor::GetVisitorName() const {
    return name_;
}
int Visitor::GetVisitorAge() const {
    return age_;
}
bool Visitor::GetVisitorHasTicket() const {
    return hasTicket_;
}

void Visitor::SetVisitorName(std::string name) {
    this->name_ = name;
}
void Visitor::SetVisitorAge(int age) {
    this->age_ = age;
}
void Visitor::SetVisitorHasTicket(bool hasTicket) {
    this->hasTicket_ = hasTicket;
}