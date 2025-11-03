//
// Created by user on 03.11.2025.
//

#ifndef LABWORK2_TOUR_H
#define LABWORK2_TOUR_H
#include <string>
#include <vector>
#include "../../Halls/Hall.h"
#include "../../Visitor/Visitor.h"

class Tour {
    public:
    Tour() = default;
    ~Tour() = default;

    std::string GetTourName() const;
    std::string GetTheme() const;
    int GetDuration() const;
    int GetMaxVisitors() const;
    std::vector<Hall*> GetRoute() const;
    std::vector<Visitor*> GetVisitors() const;
    int GetVisitorsCount() const;
    int GetHallsCount() const;
    bool IsFull() const;

    void SetTourName(std::string tourName);
    void SetTheme(std::string theme);
    void SetDuration(int durationMinutes);
    void SetMaxVisitors(int maxVisitors);

    void AddHall(Hall* hall);
    void RemoveHall(int hallNumber);
    void InsertHall(int position, Hall* hall);
    void ClearRoute();
    void ReverseRoute();

    void AddVisitor(Visitor* visitor);
    void RemoveVisitor(std::string visitorName);
    void ClearVisitors();

    void StartTour();
    void MoveToNextHall();
    void EndTour();
    Hall* GetCurrentHall() const;
    bool IsActive() const;
    int GetCurrentHallIndex() const;
private:
    std::string tourName_;
    std::string theme_;
    int duration_ = 60;
    int maxVisitors_ = 20;
    std::vector<Hall*> route_;
    std::vector<Visitor*> visitors_;
    bool isActive_ = false;
    int currentHallIndex_ = 0;
};

#endif //LABWORK2_TOUR_H