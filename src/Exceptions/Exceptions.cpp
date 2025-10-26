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