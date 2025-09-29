//
// Created by Komp on 28.09.2025.
//

#include "../Include/ReadFile.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<string, string>> ReadFile::ReadDictionary(const std::string& filename) {
    vector<pair<string, string>> dictionary;

    if (!FileExists(filename)) {
        cout << "File does not exist" << endl;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error! Failed to open the file!" << endl;
        return dictionary;
    }

    string line;
    int WordCount = 0;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        size_t pos = line.find('=');
        if (pos != string::npos) {
            string EnWord = line.substr(0, pos);
            string RuTranslation = line.substr(pos + 1);

            if (!EnWord.empty() && !RuTranslation.empty()) {
                dictionary.push_back(make_pair(EnWord, RuTranslation));
                WordCount++;
            }
        }
    }
    file.close();
    cout << "Successfully loaded the dictionary from your file!" << endl;
    return dictionary;
}

bool ReadFile::FileExists(const std::string& filename) {
    ifstream file(filename);
    return file.good();
}