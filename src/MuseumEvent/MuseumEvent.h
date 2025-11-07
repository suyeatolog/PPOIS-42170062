//
// Created by user on 06.11.2025.
//

#ifndef LABWORK2_MUSEUMEVENT_H
#define LABWORK2_MUSEUMEVENT_H
#include <vector>
#include <string>
#include "../Visitor/Visitor.h"
#include "../Halls/Hall.h"

class MuseumEvent {
    public:
    MuseumEvent() = default;
    ~MuseumEvent() = default;

    std::string GetEventName() const;
    std::string GetEventType() const;
    std::string GetEventDescription() const;
    int GetMaxParticipants() const;
    int GetDuration() const;
    Hall* GetHall() const;
    std::vector<Visitor*> GetParticipants() const;
    int CountParticipants() const;
    bool IsFull() const;
    bool IsActive() const;

    void SetEventName(std::string name);
    void SetEventType(std::string type);
    void SetEventDescription(std::string description);
    void SetMaxParticipants(int amount);
    void SetDuration(int duration);
    void SetHall(Hall* hall);
    void SetIsActive(bool isActive);

    void AddParticipant(Visitor* visitor);
    void RemoveParticipant(std::string visitorName);
    bool IsParticipantRegistered(std::string visitorName);

    void StartEvent();
    void EndEvent();

    private:
    std::string eventName_;
    std::string eventType_;
    std::string description_;
    int maxParticipants_ = 50;
    int duration_ = 60;
    bool isActive_ = false;
    Hall* hall_ = nullptr;
    std::vector<Visitor*> participants_;
};

#endif //LABWORK2_MUSEUMEVENT_H