//
// Created by Komp on 27.09.2025.
//

#include "../Include/Menu.h"
#include "../Include/ReadFile.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <limits>

using namespace std;

void Menu::PrintMenu() {
    cout << "╔══════════════════════════════════╗" << endl;
    cout << "║    English-Russian Dictionary    ║" << endl;
    cout << "╠══════════════════════════════════╣" << endl;
    cout << "║ 1. Add new word                  ║" << endl;
    cout << "║ 2. Translate a word              ║" << endl;
    cout << "║ 3. Print full dictionary         ║" << endl;
    cout << "║ 4. Read dictionary from file     ║" << endl;
    cout << "║ 5. Delete word                   ║" << endl;
    cout << "║ 6. Change translation            ║" << endl;
    cout << "║ 7. Print word count              ║" << endl;
    cout << "║ 0. Exit                          ║" << endl;
    cout << "╚══════════════════════════════════╝" << endl;
    cout << "Your choice: ";
}

void Menu::AddWord() {
    string EnWord, RuTranslation;

    cout << "Enter english word: ";
    cin >> EnWord;

    if (Dictionary.WordExists(EnWord)) {
        cout << "Word already exists!" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter russian translate: ";
    getline(cin, RuTranslation);

    Dictionary += make_pair(EnWord, RuTranslation);
    cout << "The word " << EnWord << " is added to a dictionary!" << endl;
}

void Menu::TranslateWord() {
    string EnWord;
    cout << "Enter english word to find translation: ";
    cin >> EnWord;
    string RuTranslation = Dictionary[EnWord];
    cout << "The word: " << EnWord << endl << "Translation: " << RuTranslation << endl;
}

void Menu::DeleteWord() {
    string EnWord;
    cout << "Enter english word to delete: ";
    cin >> EnWord;

    Dictionary -= EnWord;
    cout << "The word " << EnWord << " is deleted!" << endl;
}

void Menu::ChangeTranslation() {
    string EnWord, NewRuTranslation;
    cout << "Enter english word to change translation: ";
    cin >> EnWord;
    cin.ignore(1000, '\n');
    cout << "Enter new russian translation: ";
    getline(cin, NewRuTranslation);

    Dictionary.ChangeTranslation(EnWord, NewRuTranslation);
}

void Menu::PrintWordCount() {
    cout << "The amount of words in dictionary equals " << Dictionary.GetWordCount() << endl;
}

void Menu::PrintDictionary() {
    if (Dictionary.IsEmpty()) {
        cout << "The dictionary is empty!" << endl;
    }
    else {
        Dictionary.PrintDictionary();
    }
}

void Menu::LoadDictionaryFromFile() {
    string filename = "C:\\STUDYING\\PPOIS\\labwork1\\lab1Dictionary\\Input\\DictionaryInput.txt";

    auto WordPairs = ReadFile::ReadDictionary(filename);

    if (!WordPairs.empty()) {
        Dictionary.ClearDictionaryForFile();

        for (const auto& pair : WordPairs) {
            Dictionary += pair;
        }
        cout << "Successfully loaded dictionary from " << filename << endl;
    }
    else {
        cout << "Failed to load dictionary from " << filename << endl;
    }
}

void Menu::RunMenu() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int choice = -1;

    while (choice != 0) {
        cout << endl;
        PrintMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "=== Adding a word ===" << endl;
                AddWord();
                break;
            case 2:
                cout << "=== Translating a word ===" << endl;
                TranslateWord();
                break;
            case 3:
                cout << "=== Printing full dictionary ===" << endl;
                PrintDictionary();
                break;
            case 4:
                cout << "=== Reading from file ===" << endl;
                LoadDictionaryFromFile();
                break;
            case 5:
                cout << "=== Deleting a word ===" << endl;
                DeleteWord();
                break;
            case 6:
                cout << "=== Changing translation ===" << endl;
                ChangeTranslation();
                break;
            case 7:
                cout << "=== Printing word count ===" << endl;
                PrintWordCount();
                break;
            case 0:
                cout << "=== Good Bye ===" << endl;
                break;
            default:
                cout << "=== Wrong Input ===" << endl;
                break;
        }
    }
}