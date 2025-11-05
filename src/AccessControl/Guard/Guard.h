#ifndef LABWORK2_GUARD_H
#define LABWORK2_GUARD_H
#include <string>
#include "../../Visitor/Visitor.h"
#include "../TicketWindow/TicketWindow.h"

class Guard {
    public:
    Guard() = default;
    ~Guard() = default;

    std::string GetGuardName() const;
    int GetGuardAge() const;

    void SetGuardName(std::string name);
    void SetGuardAge(int age);

    void CheckSuspiciousVisitor(Visitor& visitor, TicketWindow& ticketWindow);
private:
    std::string guardName_;
    int guardAge_ = 0;
};

#endif //LABWORK2_GUARD_H