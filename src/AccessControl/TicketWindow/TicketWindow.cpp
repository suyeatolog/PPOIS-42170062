//
// Created by user on 24.10.2025.
//

#include "TicketWindow.h"
int TicketWindow::GetAmountOfTickets() const {
    return amountOfTickets_;
}
int TicketWindow::GetTotalGain() const {
    return totalGain_;
}

void TicketWindow::SetAmountOfTickets(int amount) {
    this->amountOfTickets_ = amount;
}

void TicketWindow::SellTicket(Visitor& visitor, Ticket& ticket) {
    this->amountOfTickets_ -= 1;
    this->totalGain_ += ticket.GetTicketPrice();
    visitor.SetVisitorHasTicket(true);
}