#ifndef LABWORK1_POLYNOMIAL_H
#define LABWORK1_POLYNOMIAL_H

#include <iostream>
#include <vector>

class Polynomial {
    public:
    Polynomial(const std::vector<double>& coefficients = {0.0});

    double& operator[](int index);
    double operator()(double x) const;

    Polynomial operator+(const Polynomial& OtherPolynomial) const;
    Polynomial operator-(const Polynomial& OtherPolynomial) const;
    Polynomial operator*(const Polynomial& OtherPolynomial) const;
    Polynomial operator/(const Polynomial& OtherPolynomial) const;

    Polynomial& operator+=(const Polynomial& OtherPolynomial);
    Polynomial& operator-=(const Polynomial& OtherPolynomial);
    Polynomial& operator*=(const Polynomial& OtherPolynomial);
    Polynomial& operator/=(const Polynomial& OtherPolynomial);

    void print() const;
    int getDegree() const;

private:
    std::vector<double> PolynomialCoefficients_;
};

#endif //LABWORK1_POLYNOMIAL_H