//
// Created by user on 24.10.2025.
//

#include "TicketWindow.h"

#include "../../Exceptions/Exceptions.h"

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
    if (amountOfTickets_ <= 0) {
        throw NoTicketsAvailableException("No tickets available for sale.");
    }
    if (ticket.GetTicketPrice() < 0) {
        throw InvalidTicketPriceException("Ticket price cannot be negative.");
    }
    this->amountOfTickets_ -= 1;
    this->totalGain_ += ticket.GetTicketPrice();
    visitor.SetVisitorHasTicket(true);
}