#include "Checkpoint.h"
#include "../../Exceptions/Exceptions.h"

void Checkpoint::CheckAccess(Visitor &visitor, Guard &guard, TicketWindow &ticketWindow) {
    guard.CheckSuspiciousVisitor(visitor, ticketWindow);
    if (!visitor.GetVisitorHasTicket()) {
        throw NoTicketException("Visitor doesn't have a ticket.");
    }

    visitor.SetVisitorHasAccess(true);
}

int Checkpoint::GetCheckpointNumber() const {
    return checkpointNumber_;
}
void Checkpoint::SetCheckpointNumber(int number) {
    this->checkpointNumber_ = number;
}