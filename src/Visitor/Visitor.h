//
// Created by user on 25.10.2025.
//

#ifndef LABWORK2_VISITOR_H
#define LABWORK2_VISITOR_H
#include <string>

class Visitor {
    public:
    std::string GetVisitorName() const;
    int GetVisitorAge() const;
    bool GetVisitorHasTicket() const;
    bool GetVisitorHasAccess() const;
    bool GetVisitorIsSuspicious() const;
    bool GetVisitorIsDangerous() const;

    void SetVisitorName(std::string name);
    void SetVisitorAge(int age);
    void SetVisitorHasTicket(bool hasTicket);
    void SetVisitorHasAccess(bool hasAccess);
    void SetVisitorIsSuspicious(bool isSuspicious);
    void SetVisitorIsDangerous(bool isDangerous);
private:
    std::string name_;
    int age_ = 0;
    bool hasTicket_ = false;
    bool hasAccessToMuseum_ = false;
    bool isSuspicious_ = false;
    bool isDangerous_ = false;
};

#endif //LABWORK2_VISITOR_H