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

    void SetVisitorName(std::string name);
    void SetVisitorAge(int age);
    void SetVisitorHasTicket(bool hasTicket);
private:
    std::string name_;
    int age_ = 0;
    bool hasTicket_ = false;
};

#endif //LABWORK2_VISITOR_H