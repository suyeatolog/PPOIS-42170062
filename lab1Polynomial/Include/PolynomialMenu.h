//
// Created by user on 02.10.2025.
//

#ifndef LABWORK1_POLYNOMIALMENU_H
#define LABWORK1_POLYNOMIALMENU_H

#include "Polynomial.h"
#include <vector>

class PolynomialMenu {
    public:

    void RunMenu();

    private:

    std::vector<Polynomial> Polynomials_;

    void PrintMenu();
    void CreatePolynomial();
    void PrintPolynomial();
    void EvaluatePolynomial();
    void AddPolynomials();
    void SubtractPolynomials();
    void MultiplyPolynomials();
    void DividePolynomials();
    void ListPolynomials();

    int GetPolynomialIndex();
    void PrintPolynomialList();
};

#endif //LABWORK1_POLYNOMIALMENU_H