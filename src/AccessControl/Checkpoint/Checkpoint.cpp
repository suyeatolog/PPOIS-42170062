#include "Checkpoint.h"
#include <iostream>
#include "../../Exceptions/Exceptions.h"

void Checkpoint::CheckAccess(Visitor &visitor) {
    if (!visitor.GetVisitorHasTicket()) {
        throw NoTicketException("Visitor doesn't have a ticket.");
    }

    visitor.SetVisitorHasAccess(true);
    std::cout << "Access granted to " << visitor.GetVisitorName() << std::endl;
}
