//
// Created by user on 24.10.2025.
//

#include "Ticket.h"
std::string Ticket::GetTicketName() const {
    return ticketName_;
}
int Ticket::GetTicketNumber() const {
    return ticketNumber_;
}
int Ticket::GetTicketPrice() const {
    return ticketPrice_;
}

void Ticket::SetTicketName(std::string ticketName) {
    this->ticketName_ = ticketName;
}
void Ticket::SetTicketNumber(int ticketNumber) {
    this->ticketNumber_ = ticketNumber;
}
void Ticket::SetTicketPrice(int ticketPrice) {
    this->ticketPrice_ = ticketPrice;
}