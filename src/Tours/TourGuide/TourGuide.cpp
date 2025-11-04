#include "TourGuide.h"
#include "../../Exceptions/Exceptions.h"

TourGuide::TourGuide() {
    specialization_ = "General";
}

TourGuide::~TourGuide() {
    if (currentTour_ != nullptr) {
        delete currentTour_;
        currentTour_ = nullptr;
    }
}

std::string TourGuide::GetName() const {
    return name_;
}

int TourGuide::GetEmployeeId() const {
    return employeeId_;
}

std::string TourGuide::GetSpecialization() const {
    return specialization_;
}

int TourGuide::GetExperienceYears() const {
    return experienceYears_;
}

std::vector<std::string> TourGuide::GetLanguages() const {
    return languages_;
}

bool TourGuide::GetIsAvailable() const {
    return isAvailable_;
}

int TourGuide::GetToursCount() const {
    return toursCompleted_;
}

Tour* TourGuide::GetCurrentTour() const {
    return currentTour_;
}

void TourGuide::SetName(std::string tourGuideName) {
    this->name_ = tourGuideName;
}

void TourGuide::SetEmployeeId(int id) {
    this->employeeId_ = id;
}

void TourGuide::SetSpecialization(std::string specialization) {
    this->specialization_ = specialization;
}

void TourGuide::SetExperienceYears(int years) {
    this->experienceYears_ = years;
}

void TourGuide::SetLanguages(const std::vector<std::string>& languages) {
    this->languages_ = languages;
}

void TourGuide::CreateTour(std::string tourName, std::string theme) {
    if (!isAvailable_) {
        throw TourGuideNotAvailableException("Cannot create new tour, because guide is busy");
    }
    if (currentTour_ != nullptr) {
        delete currentTour_;
        currentTour_ = nullptr;
    }
    currentTour_ = new Tour();
    currentTour_->SetTourName(tourName);
    currentTour_->SetTheme(theme);
}
void TourGuide::StartTour() {
    if (!isAvailable_) {
        throw TourGuideNotAvailableException("Cannot start tour, because guide is not available");
    }
    if (currentTour_ == nullptr) {
        throw InvalidTourParametersException("No tour created to start");
    }
    currentTour_->StartTour();
    isAvailable_ = false;
    toursConducted_++;
}
void TourGuide::EndTour() {
    if (currentTour_ == nullptr) {
        throw InvalidTourParametersException("No active tour to end");
    }
    if (currentTour_->IsActive()) {
        currentTour_->EndTour();
        toursCompleted_++;
    }
    isAvailable_ = true;
    delete currentTour_;
    currentTour_ = nullptr;
}
void TourGuide::MoveToNextHall() {
    if (currentTour_ == nullptr) {
        throw InvalidTourParametersException("No active tour to move");
    }
    currentTour_->MoveToNextHall();
}
void TourGuide::AddHallToRoute(Hall *hall) {
    if (currentTour_ == nullptr) {
        throw InvalidTourParametersException("No active tour to add hall");
    }

    if (!CanGuideHall(hall)) {
        throw GuideSpecializationMismatchException("Guide cannot conduct this tour");
    }
    currentTour_->AddHall(hall);
}
void TourGuide::AddVisitorToTour(Visitor *visitor) {
    if (currentTour_ == nullptr) {
        throw InvalidTourParametersException("No active tour to add visitor");
    }
    currentTour_->AddVisitor(visitor);
}
void TourGuide::AddLanguage(std::string language) {
    if (!SpeaksLanguage(language)) {
        languages_.push_back(language);
    }
}
void TourGuide::RemoveLanguage(std::string language) {
    for (int i = 0; i < languages_.size(); i++) {
        if (languages_[i] == language) {
            languages_.erase(languages_.begin() + i);
            break;
        }
    }
}
bool TourGuide::SpeaksLanguage(std::string language) const {
    for (int i = 0; i < languages_.size(); i++) {
        if (languages_[i] == language) {
            return true;
        }
    }
    return false;
}
bool TourGuide::CanGuideHall(Hall* hall) const {
    if (!hall) return false;

    std::string hallType = hall->GetHallType();

    if (specialization_ == "General") return true;

    if (specialization_ == hallType) return true;

    return false;
}

double TourGuide::CalculateTourSuccessRate() const {
    if (toursConducted_ == 0) return 0.0;
    double completed = toursCompleted_;
    double conducted = toursConducted_;
    return completed / conducted;
}