//
// Created by Komp on 27.09.2025.
//

#ifndef LABWORK1_MENU_H
#define LABWORK1_MENU_H
#include "Dictionary.h"

class Menu {
public:
    void RunMenu();
private:
    Dictionary Dictionary;

    void PrintMenu();
    void AddWord();
    void DeleteWord();
    void ChangeTranslation();
    void PrintWordCount();
    void TranslateWord();
    void PrintDictionary();
    void LoadDictionaryFromFile();
};

#endif //LABWORK1_MENU_H