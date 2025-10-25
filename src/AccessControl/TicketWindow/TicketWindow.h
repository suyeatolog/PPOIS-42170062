//
// Created by user on 24.10.2025.
//

#ifndef LABWORK2_TICKETWINDOW_H
#define LABWORK2_TICKETWINDOW_H
#include "../Ticket/Ticket.h"
#include <string>

class TicketWindow {
    public:
    TicketWindow() = default;
    ~TicketWindow() = default;

    int GetAmountOfTickets() const;
    int GetTotalGain() const;

    void SetAmountOfTickets(int amount);

    void SellTickets(int amountOfTickets);

    private:
    int amountOfTickets_ = 0;
    int totalGain_ = 0;
};

#endif //LABWORK2_TICKETWINDOW_H