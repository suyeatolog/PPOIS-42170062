//
// Created by user on 24.10.2025.
//

#ifndef LABWORK2_TICKET_H
#define LABWORK2_TICKET_H
#include <string>

class Ticket {
    public:
    Ticket() = default;
    ~Ticket() = default;

    std::string GetTicketName() const;
    int GetTicketNumber() const;
    int GetTicketPrice() const;

    void SetTicketName(std::string ticketName);
    void SetTicketNumber(int ticketNumber);
    void SetTicketPrice(int ticketPrice);

private:
    std::string ticketName_;
    int ticketNumber_ = 0;
    int ticketPrice_ = 0;
};

#endif //LABWORK2_TICKET_H