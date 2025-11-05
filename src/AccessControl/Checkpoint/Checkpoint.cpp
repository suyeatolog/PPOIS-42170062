#include "Checkpoint.h"
#include "../../Exceptions/Exceptions.h"

void Checkpoint::CheckAccess(Visitor &visitor, Guard &guard, TicketWindow &ticketWindow) {
    guard.CheckSuspiciousVisitor(visitor, ticketWindow);
    if (!visitor.GetVisitorHasTicket()) {
        throw NoTicketException("Visitor doesn't have a ticket.");
    }

    visitor.SetVisitorHasAccess(true);
}
