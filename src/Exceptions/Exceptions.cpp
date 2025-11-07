//
// Created by user on 25.10.2025.
//

#include "Exceptions.h"
Exception::Exception(const char* message) : message_(message) {}

const char* Exception::what() const noexcept {
    return message_.c_str();
}

NoTicketsAvailableException::NoTicketsAvailableException(const char* message) : Exception(message) {}

InvalidTicketPriceException::InvalidTicketPriceException(const char *message) : Exception(message) {}

NoTicketException::NoTicketException(const char* message) : Exception(message) {}

InvalidAgeException::InvalidAgeException(const char* message) : Exception(message) {}

EmptyNameException::EmptyNameException(const char* message) : Exception(message) {}

TourException::TourException(const char* message) : Exception(message) {}

EmptyTourRouteException::EmptyTourRouteException(const char* message) : TourException(message) {}

TourFullException::TourFullException(const char* message) : TourException(message) {}

TourNotActiveException::TourNotActiveException(const char* message) : TourException(message) {}

InvalidTourParameterException::InvalidTourParameterException(const char* message) : TourException(message) {}

TourGuideException::TourGuideException(const char* message) : Exception(message) {}

TourGuideNotAvailableException::TourGuideNotAvailableException(const char* message) : TourGuideException(message) {}

TourAlreadyInProgressException::TourAlreadyInProgressException(const char* message) : TourGuideException(message) {}

InvalidTourParametersException::InvalidTourParametersException(const char* message) : TourGuideException(message) {}

GuideSpecializationMismatchException::GuideSpecializationMismatchException(const char* message) : TourGuideException(message) {}

InvalidVisitorParameterException::InvalidVisitorParameterException(const char *message) : Exception(message) {}

FullParticipantsException::FullParticipantsException(const char *message) : Exception(message) {}

VisitorAlreadyRegistered::VisitorAlreadyRegistered(const char *message) : Exception(message) {}
