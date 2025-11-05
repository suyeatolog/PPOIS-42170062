#include "Guard.h"
#include "../../Exceptions/Exceptions.h"

std::string Guard::GetGuardName() const {
    return guardName_;
}
int Guard::GetGuardAge() const {
    return guardAge_;
}

void Guard::SetGuardName(std::string name) {
    if (name.empty()) {
        throw EmptyNameException("Guard name cannot be empty.");
    }
    this->guardName_ = name;
}
void Guard::SetGuardAge(int age) {
    if (age < 0 || age > 150) {
        throw InvalidAgeException("Guard age cannot be negative.");
    }
    this->guardAge_ = age;
}

void Guard::CheckSuspiciousVisitor(Visitor &visitor, TicketWindow &ticketWindow) {
    if (visitor.GetVisitorIsSuspicious()) {
        if (visitor.GetVisitorIsDangerous()) {
            visitor.SetVisitorHasAccess(false);
            visitor.SetVisitorHasTicket(false);
            ticketWindow.SetAmountOfTickets(ticketWindow.GetAmountOfTickets() + 1);
        } else {
            visitor.SetVisitorIsSuspicious(false);
        }
    }
    return;
}
