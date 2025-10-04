//
// Created by user on 02.10.2025.
//

#include "../Include/Polynomial.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Polynomial::Polynomial(const std::vector<double> &coefficients) {
    if (coefficients.empty()) {
        this->PolynomialCoefficients_.push_back(0.0);
    }
    else {
        this->PolynomialCoefficients_ = coefficients;
    }
}

double& Polynomial::operator[](int index) {
    if (index < 0) {
        throw std::out_of_range("Index is negative. Index must be Positive");
    }

    if (index >= PolynomialCoefficients_.size()) {
        PolynomialCoefficients_.resize(index + 1, 0.0);
    }

    return PolynomialCoefficients_[index];
}

double Polynomial::operator()(double x) const {
    double result = 0.0;
    double power = 1.0;

    for (int i = 0; i < PolynomialCoefficients_.size(); i++) {
        result += PolynomialCoefficients_[i] * power;
        power *= x;
    }
    return result;
}

Polynomial Polynomial::operator+(const Polynomial& OtherPolynomial) const {
    int maxSize;

    if (PolynomialCoefficients_.size() > OtherPolynomial.PolynomialCoefficients_.size()) {
        maxSize = PolynomialCoefficients_.size();
    }
    else {
        maxSize = OtherPolynomial.PolynomialCoefficients_.size();
    }

    Polynomial result;
    result.PolynomialCoefficients_.resize(maxSize, 0.0);

    for (int i = 0; i < maxSize; i++ ) {
        double sum = 0.0;

        if (i < PolynomialCoefficients_.size()) {
            sum += PolynomialCoefficients_[i];
        }
        if (i < OtherPolynomial.PolynomialCoefficients_.size()) {
            sum += OtherPolynomial.PolynomialCoefficients_[i];
        }
        result.PolynomialCoefficients_[i] = sum;
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& OtherPolynomial) const {
    int maxSize;

    if (PolynomialCoefficients_.size() > OtherPolynomial.PolynomialCoefficients_.size()) {
        maxSize = PolynomialCoefficients_.size();
    }
    else {
        maxSize = OtherPolynomial.PolynomialCoefficients_.size();
    }

    Polynomial result;
    result.PolynomialCoefficients_.resize(maxSize, 0.0);

    for (int i = 0; i < maxSize; i++ ) {
        double diff = 0.0;

        if (i < PolynomialCoefficients_.size()) {
            diff += PolynomialCoefficients_[i];
        }
        if (i < OtherPolynomial.PolynomialCoefficients_.size()) {
            diff -= OtherPolynomial.PolynomialCoefficients_[i];
        }
        result.PolynomialCoefficients_[i] = diff;
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& OtherPolynomial) const {
    int degree1 = PolynomialCoefficients_.size() - 1;
    int degree2 = OtherPolynomial.PolynomialCoefficients_.size() - 1;
    int resultDegree = degree1 + degree2;

    Polynomial result;
    result.PolynomialCoefficients_.resize(resultDegree + 1, 0.0);

    for (int i = 0; i < PolynomialCoefficients_.size(); i++) {
        for (int j = 0; j < OtherPolynomial.PolynomialCoefficients_.size(); j++) {
            result.PolynomialCoefficients_[i + j] = PolynomialCoefficients_[i] * OtherPolynomial.PolynomialCoefficients_[j];
        }
    }
    return result;
}

Polynomial Polynomial::operator/(const Polynomial& OtherPolynomial) const {
    if (OtherPolynomial.PolynomialCoefficients_.size() == 1 && OtherPolynomial.PolynomialCoefficients_[0] == 0) {
        throw std::invalid_argument("Polynomial Divided by Zero");
    }

    bool allZero = true;
    for (int i = 0; i < PolynomialCoefficients_.size(); i++) {
        if (PolynomialCoefficients_[i] != 0) {
            allZero = false;
            break;
        }
    }
    if (allZero == true) {
        return Polynomial();
    }
    std::vector<double> dividendCoefficients = PolynomialCoefficients_;
    std::vector<double> quotientCoefficients(PolynomialCoefficients_.size() - OtherPolynomial.PolynomialCoefficients_.size()+1, 0.0);

    double otherLeading = OtherPolynomial.PolynomialCoefficients_.back();
    int otherDegree = OtherPolynomial.PolynomialCoefficients_.size() - 1;

    for (int i =dividendCoefficients.size() - 1; i >= otherDegree; i--) {
        if (dividendCoefficients[i] != 0) {
            double factor = dividendCoefficients[i] / otherLeading;
            int pos = i - otherDegree;
            quotientCoefficients[pos] = factor;

            for (int j = 0; j <= otherDegree; j++) {
                dividendCoefficients[i - j] -= factor * OtherPolynomial.PolynomialCoefficients_[otherDegree - j];
            }
        }
    }
    return Polynomial(quotientCoefficients);
}

Polynomial& Polynomial::operator+=(const Polynomial& OtherPolynomial) {
    *this = *this + OtherPolynomial;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& OtherPolynomial) {
    *this = *this - OtherPolynomial;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& OtherPolynomial) {
    *this = *this * OtherPolynomial;
    return *this;
}

Polynomial& Polynomial::operator/=(const Polynomial& OtherPolynomial) {
    *this = *this / OtherPolynomial;
    return *this;
}

void Polynomial::print() const {
    bool first = true;
    for (int i = PolynomialCoefficients_.size() - 1; i >= 0; i--) {
        if (PolynomialCoefficients_[i] != 0) {
            if (!first) {
                if (PolynomialCoefficients_[i] > 0) {
                    std::cout << " + ";
                }
                else {
                    std::cout << " - ";
                }
            }
            else {
                if (PolynomialCoefficients_[i] < 0) {
                    std::cout << " - ";
                }
            }
            double absCoef = std::abs(PolynomialCoefficients_[i]);

            if (i == 0) {
                std::cout << absCoef;
            }
            else if (i == 1) {
                if (absCoef != 1) {
                    std::cout << absCoef;
                }
                std::cout << "x";
            }
            else {
                if (absCoef != 1) {
                    std::cout << absCoef;
                }
                std::cout << "x^" << i;
            }
            first = false;
        }
    }
    if (first) {
        std::cout << "0";
    }

    std::cout << std::endl;
}

int Polynomial::getDegree() const {
    return PolynomialCoefficients_.size() - 1;
}