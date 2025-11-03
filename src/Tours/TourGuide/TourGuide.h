//
// Created by user on 03.11.2025.
//

#ifndef LABWORK2_TOURGUIDE_H
#define LABWORK2_TOURGUIDE_H
#include <vector>
#include <string>
#include "../Tour/Tour.h"

class TourGuide {
public:
    TourGuide() = default;
    ~TourGuide();

    std::string GetName() const;
    int GetEmployeeId() const;
    std::string GetSpecialization() const;
    int GetExperienceYears() const;
    std::vector<std::string> GetLanguages() const;
    bool GetIsAvailable() const;
    int GetToursCount() const;
    Tour* GetCurrentTour() const;

    void SetName(std::string tourGuideName);
    void SetEmployeeId(int id);
    void SetSpecialization(std::string specialization);
    void SetExperienceYears(int years);
    void SetLanguages(const std::vector<std::string>& languages);

    void CreateTour(std::string tourName, std::string theme);
    void StartTour();
    void EndTour();
    void MoveToNextHall();
    void AddHallToRoute(Hall* hall);
    void AddVisitorToTour(Visitor* visitor);

    void AddLanguage(std::string language);
    void RemoveLanguage(std::string language);
    bool SpeaksLanguage(std::string language) const;

    bool CanGuideHall(Hall* hall) const;
    double CalculateTourSuccessRate() const;
private:
    std::string name_;
    int employeeId_ = 0;
    std::string specialization_;
    int experienceYears_ = 0;
    std::vector<std::string> languages_;
    int toursCompleted_ = 0;
    int toursConducted_ = 0;
    Tour* currentTour_;
    bool isAvailable_ = true;
};

#endif //LABWORK2_TOURGUIDE_H