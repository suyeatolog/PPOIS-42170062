#include <iostream>
#include "Include/Menu.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Menu MyMenu;
    MyMenu.RunMenu();
    return 0;
}