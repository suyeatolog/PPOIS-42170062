//
// Created by user on 02.10.2025.
//
#include "../Include/PolynomialMenu.h"
#include <iostream>

using namespace std;

void PolynomialMenu::PrintMenu() {
    cout << "╔══════════════════════════════════╗" << endl;
    cout << "║       Polynomial Calculator      ║" << endl;
    cout << "╠══════════════════════════════════╣" << endl;
    cout << "║ 1. Create new polynomial         ║" << endl;
    cout << "║ 2. Print polynomial              ║" << endl;
    cout << "║ 3. Evaluate polynomial           ║" << endl;
    cout << "║ 4. Add polynomials               ║" << endl;
    cout << "║ 5. Subtract polynomials          ║" << endl;
    cout << "║ 6. Multiply polynomials          ║" << endl;
    cout << "║ 7. Divide polynomials            ║" << endl;
    cout << "║ 8. List all polynomials          ║" << endl;
    cout << "║ 0. Exit                          ║" << endl;
    cout << "╚══════════════════════════════════╝" << endl;
    cout << "Your choice: ";
}

void PolynomialMenu::CreatePolynomial() {
    int degree;
    cout << "Enter degree: ";
    cin >> degree;

    if (degree < 0) {
        cout << "Invalid degree - degree can't be negative" << endl;
        return;
    }
    vector<double> coefficients(degree + 1);
    cout << "Enter coefficients from x^0 to x^" << degree << ": " << endl;

    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient for x^" << i << ": ";
        cin >> coefficients[i];
    }

    Polynomial polynomial(coefficients);
    Polynomials_.push_back(polynomial);

    cout << "Polynomial created. Index of your polynomial: " << Polynomials_.size() - 1 << endl;
}

int PolynomialMenu::GetPolynomialIndex() {
    if (Polynomials_.empty()) {
        cout << "No polynomials created" << endl;
        return -1;
    }

    PrintPolynomialList();

    int index;
    cout << "Enter polynomial index: ";
    cin >> index;

    if (index < 0 || index >= Polynomials_.size()) {
        cout << "Invalid polynomial index" << endl;
        return -1;
    }
    return index;
}


void PolynomialMenu::PrintPolynomial() {
    if (Polynomials_.empty()) {
        cout << "Polynomials are missing. Create one." << endl;
        return;
    }

    int index = GetPolynomialIndex();
    if (index == -1) {
        return;
    }

    cout << "Polynomial " << index << ": ";
    Polynomials_[index].print();
    cout << endl;
    cout << "Degree: " << Polynomials_[index].getDegree() << endl;
}

void PolynomialMenu::EvaluatePolynomial() {
    if (Polynomials_.empty()) {
        cout << "Polynomials are missing. Create one." << endl;
        return;
    }

    int index = GetPolynomialIndex();
    if (index == -1) {
        return;
    }

    double x;
    cout << "Enter value of x: ";
    cin >> x;

    double result = Polynomials_[index](x);
    cout << "The result of evaluation: " << result << endl;
}

void PolynomialMenu::AddPolynomials() {
    if (Polynomials_.size() < 2) {
        cout << "Not enough polynomials. Need 2 or more to proceed adding." << endl;
        return;
    }

    PrintPolynomialList();

    int index1, index2;
    cout << "Enter polynomial index 1: ";
    cin >> index1;
    cout << "Enter polynomial index 2: ";
    cin >> index2;

    if (index1 < 0 || index1 >= Polynomials_.size() || index2 < 0 || index2 >= Polynomials_.size()) {
        cout << "Invalid polynomial index" << endl;
        return;
    }
    Polynomial result = Polynomials_[index1] + Polynomials_[index2];
    Polynomials_.push_back(result);

    cout << "Result is stored at index: " << Polynomials_.size() - 1 << ". Result: " << endl;
    result.print();
}

void PolynomialMenu::SubtractPolynomials() {
    if (Polynomials_.size() < 2) {
        cout << "Not enough polynomials. Need 2 or more to proceed subtracting." << endl;
        return;
    }

    PrintPolynomialList();

    int index1, index2;
    cout << "Enter polynomial index 1: ";
    cin >> index1;
    cout << "Enter polynomial index 2: ";
    cin >> index2;

    if (index1 < 0 || index1 >= Polynomials_.size() || index2 < 0 || index2 >= Polynomials_.size()) {
        cout << "Invalid polynomial index" << endl;
        return;
    }

    Polynomial result = Polynomials_[index1] - Polynomials_[index2];
    Polynomials_.push_back(result);
    cout << "Result is stored at index: " << Polynomials_.size() - 1 << ". Result:" << endl;
    result.print();
}

void PolynomialMenu::MultiplyPolynomials() {
    if (Polynomials_.size() < 2) {
        cout << "Not enough polynomials. Need 2 or more to proceed multiplying." << endl;
        return;
    }

    PrintPolynomialList();

    int index1, index2;
    cout << "Enter polynomial index 1: ";
    cin >> index1;
    cout << "Enter polynomial index 2: ";
    cin >> index2;

    if (index1 < 0 || index1 >= Polynomials_.size() || index2 < 0 || index2 >= Polynomials_.size()) {
        cout << "Invalid polynomial index" << endl;
        return;
    }

    Polynomial result = Polynomials_[index1] * Polynomials_[index2];
    Polynomials_.push_back(result);

    cout << "Result is stored at index: " << Polynomials_.size() - 1 << ". Result:" << endl;
    result.print();
}

void PolynomialMenu::DividePolynomials() {
    if (Polynomials_.size() < 2) {
        cout << "Not enough polynomials. Need 2 or more to proceed dividing." << endl;
        return;
    }

    PrintPolynomialList();

    int index1, index2;
    cout << "Enter polynomial index 1: ";
    cin >> index1;
    cout << "Enter polynomial index 2: ";
    cin >> index2;

    if (index1 < 0 || index1 >= Polynomials_.size() || index2 < 0 || index2 >= Polynomials_.size()) {
        cout << "Invalid polynomial index" << endl;
        return;
    }

    try {
        Polynomial result = Polynomials_[index1] / Polynomials_[index2];
        Polynomials_.push_back(result);

        cout << "Result is stored at index: " << Polynomials_.size() - 1 << ". Result:" << endl;
        result.print();
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void PolynomialMenu::ListPolynomials() {
    if (Polynomials_.empty()) {
        cout << "Polynomials are missing. Create one." << endl;
        return;
    }

    cout << "List of polynomials: " << endl;

    for (int i = 0; i < Polynomials_.size(); i++) {
        cout << i << " polynomial: " << endl;
        Polynomials_[i].print();
    }
}

void PolynomialMenu::PrintPolynomialList() {
    cout << "Available polynomials:" << endl;

    for (int i = 0; i < Polynomials_.size(); i++) {
        cout << i << " polynomial: " << endl;
        Polynomials_[i].print();
    }
}

void PolynomialMenu::RunMenu() {
    int choice = -1;

    while (choice != 0) {
        cout << endl;
        PrintMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                CreatePolynomial();
                break;
            }
            case 2: {
                PrintPolynomial();
                break;
            }
            case 3: {
                EvaluatePolynomial();
                break;
            }
            case 4: {
                AddPolynomials();
                break;
            }
            case 5: {
                SubtractPolynomials();
                break;
            }
            case 6: {
                MultiplyPolynomials();
                break;
            }
            case 7: {
                DividePolynomials();
                break;
            }
            case 8: {
                ListPolynomials();
                break;
            }
            case 0: {
                cout << "GoodBye." << endl;
                break;
            }
            default: {
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }
}
