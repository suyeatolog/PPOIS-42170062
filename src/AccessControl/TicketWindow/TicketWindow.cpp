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

void TicketWindow::SellTickets(int amountOfTickets) {
    this->amountOfTickets_ -= amountOfTickets;
    totalGain_ += amountOfTickets;
}