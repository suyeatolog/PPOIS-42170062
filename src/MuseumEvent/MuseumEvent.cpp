#include "MuseumEvent.h"
#include "../Exceptions/Exceptions.h"

std::string MuseumEvent::GetEventName() const {
    return eventName_;
}
std::string MuseumEvent::GetEventType() const {
    return eventType_;
}
std::string MuseumEvent::GetEventDescription() const {
    return description_;
}
int MuseumEvent::GetMaxParticipants() const {
    return maxParticipants_;
}
int MuseumEvent::GetDuration() const {
    return duration_;
}
Hall* MuseumEvent::GetHall() const {
    return hall_;
}
std::vector<Visitor *> MuseumEvent::GetParticipants() const {
    return participants_;
}
int MuseumEvent::CountParticipants() const {
    return participants_.size();
}
bool MuseumEvent::IsFull() const {
    return participants_.size() == maxParticipants_;
}
bool MuseumEvent::IsActive() const {
    return isActive_;
}

void MuseumEvent::SetEventName(std::string eventName) {
    this->eventName_ = eventName;
}
void MuseumEvent::SetEventType(std::string eventType) {
    this->eventType_ = eventType;
}
void MuseumEvent::SetEventDescription(std::string description) {
    this->description_ = description;
}
void MuseumEvent::SetMaxParticipants(int maxParticipants) {
    this->maxParticipants_ = maxParticipants;
}
void MuseumEvent::SetDuration(int duration) {
    this->duration_ = duration;
}
void MuseumEvent::SetHall(Hall* hall) {
    this->hall_ = hall;
}
void MuseumEvent::SetIsActive(bool isActive) {
    this->isActive_ = isActive;
}
void MuseumEvent::AddParticipant(Visitor* visitor) {
    if (!visitor) {
        throw InvalidVisitorParameterException("Invalid visitor");
    }
    if (IsFull()) {
        throw FullParticipantsException("Can't add, because full participants");
    }
    if (IsParticipantRegistered(visitor->GetVisitorName())) {
        throw VisitorAlreadyRegistered("Can't add visitor, because visitor already registered");
    }
    participants_.push_back(visitor);
}
void MuseumEvent::RemoveParticipant(std::string visitorName) {
    for (int i = 0; i < participants_.size(); i++) {
        if (participants_[i]->GetVisitorName() == visitorName) {
            participants_.erase(participants_.begin() + i);
            break;
        }
    }
}
bool MuseumEvent::IsParticipantRegistered(std::string visitorName) {
    for (int i = 0; i < participants_.size(); i++) {
        if (participants_[i]->GetVisitorName() == visitorName) {
            return true;
        }
    }
    return false;
}

void MuseumEvent::StartEvent() {
    if (isActive_) return;
    if (!hall_) return;

    this->isActive_ = true;
}

void MuseumEvent::EndEvent() {
    this->isActive_ = false;
}