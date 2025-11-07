//
// Created by user on 25.10.2025.
//

#ifndef LABWORK2_EXCEPTIONS_H
#define LABWORK2_EXCEPTIONS_H
#include <string>
#include <exception>

class Exception : public std::exception {
    public:
    explicit Exception(const char* message);
    const char* what() const noexcept override;

    private:
    std::string message_;
};

class NoTicketsAvailableException : public Exception {
public:
    explicit NoTicketsAvailableException(const char* message);
};

class InvalidTicketPriceException : public Exception {
public:
    explicit InvalidTicketPriceException(const char* message);
};

class NoTicketException : public Exception {
public:
    explicit NoTicketException(const char* message);
};

class InvalidAgeException : public Exception {
public:
    explicit InvalidAgeException(const char* message);
};

class EmptyNameException : public Exception {
public:
    explicit EmptyNameException(const char* message);
};

class TourException : public Exception {
public:
    explicit TourException(const char* message);
};

class EmptyTourRouteException : public TourException {
public:
    explicit EmptyTourRouteException(const char* message);
};

class TourFullException : public TourException {
public:
    explicit TourFullException(const char* message);
};

class TourNotActiveException : public TourException {
public:
    explicit TourNotActiveException(const char* message);
};

class InvalidTourParameterException : public TourException {
public:
    explicit InvalidTourParameterException(const char* message);
};

class TourGuideException : public Exception {
public:
    explicit TourGuideException(const char* message);
};

class TourGuideNotAvailableException : public TourGuideException {
public:
    explicit TourGuideNotAvailableException(const char* message);
};

class TourAlreadyInProgressException : public TourGuideException {
public:
    explicit TourAlreadyInProgressException(const char* message);
};

class InvalidTourParametersException : public TourGuideException {
public:
    explicit InvalidTourParametersException(const char* message);
};

class GuideSpecializationMismatchException : public TourGuideException {
public:
    explicit GuideSpecializationMismatchException(const char* message);
};

class InvalidVisitorParameterException : public Exception {
    public:
    explicit InvalidVisitorParameterException(const char* message);
};

class FullParticipantsException : public Exception {
public:
    explicit FullParticipantsException(const char* message);
};

class VisitorAlreadyRegistered : public Exception {
public:
    explicit VisitorAlreadyRegistered(const char* message);
};
#endif //LABWORK2_EXCEPTIONS_H