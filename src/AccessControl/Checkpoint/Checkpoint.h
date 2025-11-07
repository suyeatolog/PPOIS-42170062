#ifndef LABWORK2_CHECKPOINT_H
#define LABWORK2_CHECKPOINT_H
#include "../../Visitor/Visitor.h"
#include "../Guard/Guard.h"
#include "../TicketWindow/TicketWindow.h"

class Checkpoint {
public:
    Checkpoint() = default;
    ~Checkpoint() = default;

    void CheckAccess(Visitor& visitor, Guard& guard, TicketWindow& ticketWindow);
};

#endif //LABWORK2_CHECKPOINT_H