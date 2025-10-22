//
// Created by user on 22.10.2025.
//

#ifndef LABWORK2_HALL_H
#define LABWORK2_HALL_H
#include <string>
#include "../Exhibition/Exhibition.h"

class Hall {
public:
    Hall() = default;
    virtual ~Hall() = default;

    std::string GetHallName() const;
    int GetHallNumber() const;
    double GetHallArea() const;
    int GetHallCapacity() const;

    void SetHallName(std::string name);
    void SetHallNumber(int number);
    void SetHallArea(double area);
    void SetHallCapacity(int capacity);

    void SetCurrentExhibition(Exhibition* exhibition);
    Exhibition* GetCurrentExhibition() const;
    bool HasExhibition() const;

    virtual std::string GetHallType() const = 0;

    protected:
    std::string hallName_;
    int hallNumber_ = 0;
    double area_ = 0;
    int capacity_ = 0;

    Exhibition* currentExhibition_ = nullptr;
};

#endif //LABWORK2_HALL_H