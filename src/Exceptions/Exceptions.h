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
#endif //LABWORK2_EXCEPTIONS_H