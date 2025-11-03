#include "Tour.h"
#include "../../Exceptions/Exceptions.h"

std::string Tour::GetTourName() const {
    return tourName_;
}
std::string Tour::GetTheme() const {
    return theme_;
}
int Tour::GetDuration() const {
    return duration_;
}
int Tour::GetMaxVisitors() const {
    return maxVisitors_;
}
std::vector<Hall*> Tour::GetRoute() const {
    return route_;
}
std::vector<Visitor*> Tour::GetVisitors() const {
    return visitors_;
}
int Tour::GetVisitorsCount() const {
    return visitors_.size();
}
int Tour::GetHallsCount() const {
    return route_.size();
}
bool Tour::IsFull() const {
    return visitors_.size() >= maxVisitors_;
}

void Tour::SetTourName(std::string tourName) {
    this->tourName_ = tourName;
}
void Tour::SetTheme(std::string theme) {
    this->theme_ = theme;
}
void Tour::SetDuration(int durationMinutes) {
    this->duration_ = durationMinutes;
}
void Tour::SetMaxVisitors(int maxVisitors) {
    this->maxVisitors_ = maxVisitors;
}

void Tour::AddHall(Hall* hall) {
    if (!hall) {
        throw InvalidTourParameterException("Cannot add null hall to route");
    }
    this->route_.push_back(hall);
}
void Tour::RemoveHall(int hallNumber) {
    for (int i = 0; i < route_.size(); i++) {
        if (route_[i]->GetHallNumber() == hallNumber) {
            this->route_.erase(route_.begin() + i);
            break;
        }
    }
}
void Tour::InsertHall(int position, Hall* hall) {
    if (!hall) {
        throw InvalidTourParameterException("Cannot insert null hall to tour route");
    }
    if (position < 0 || position > route_.size()) {
        throw InvalidTourParameterException("Invalid position for inserting hall");
    }
    this->route_.insert(route_.begin() + position, hall);
}
void Tour::ClearRoute() {
    this->route_.clear();
    this->currentHallIndex_ = -1;
}
void Tour::ReverseRoute() {
    for (int i = 0; i < route_.size(); i++) {
        Hall* temp = route_[i];
        route_[i] = route_[route_.size() - 1 - i];
        route_[route_.size() - 1 - i] = temp;
    }
}

void Tour::AddVisitor(Visitor *visitor) {
    if (!visitor) {
        throw InvalidTourParameterException("Cannot add null visitor to route");
    }
    if (IsFull()) {
        throw TourFullException("Tour is full, cannot add more visitors");
    }
    this->visitors_.push_back(visitor);
}
void Tour::RemoveVisitor(std::string visitorName) {
    for (int i = 0; i < visitors_.size(); i++) {
        if (visitors_[i]->GetVisitorName() == visitorName) {
            this->visitors_.erase(this->visitors_.begin() + i);
            break;
        }
    }
}
void Tour::ClearVisitors() {
    this->visitors_.clear();
}

void Tour::StartTour() {
    if (route_.empty()) {
        throw EmptyTourRouteException("Cannot start tour, because the route is empty");
    }
    if (visitors_.empty()) {
        throw EmptyTourRouteException("Cannot start tour, because there are no visitors");
    }

    isActive_ = true;
    currentHallIndex_ = 0;
}
void Tour::MoveToNextHall() {
    if (!isActive_) {
        throw TourNotActiveException("Tour is not active");
    }

    if (currentHallIndex_ < route_.size()) {
        currentHallIndex_++;
    } else {
        EndTour();
    }
}
void Tour::EndTour() {
    if (!isActive_) {
        throw TourNotActiveException("Tour is not active");
    }
    isActive_ = false;
    currentHallIndex_ = -1;
}
Hall* Tour::GetCurrentHall() const {
    if (isActive_ && currentHallIndex_ >= 0 && currentHallIndex_ < route_.size()) {
        return route_[currentHallIndex_];
    }
    return nullptr;
}
bool Tour::IsActive() const {
    return isActive_;
}
int Tour::GetCurrentHallIndex() const {
    return currentHallIndex_;
}