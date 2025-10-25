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

#endif //LABWORK2_EXCEPTIONS_H