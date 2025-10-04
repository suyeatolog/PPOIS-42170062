#include <iostream>
#include "../Include/PolynomialMenu.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::cout << "Polynomials" << std::endl;

    PolynomialMenu MyMenu;
    MyMenu.RunMenu();
    return 0;
}