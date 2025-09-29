//
// Created by Komp on 27.09.2025.
//

#ifndef LABWORK1_DICTIONARY_H
#define LABWORK1_DICTIONARY_H
#include "DictionaryNode.h"
#include <string>

class Dictionary {
public:
    Dictionary();
    ~Dictionary();

    Dictionary& operator+=(std::pair<std::string, std::string> WordPair);
    Dictionary& operator-=(std::string EnWord);
    std::string operator[](std::string EnWord) const;

    void ChangeTranslation(std::string EnWord, std::string NewRuTranslation);
    void PrintDictionary();
    void ClearDictionaryForFile();
    bool IsEmpty();
    bool WordExists(std::string EnWord);
    int GetWordCount();

private:
    DictionaryNode* Root_;
    int WordCount_;

    DictionaryNode* Insert(DictionaryNode* node, std::string EnWord, std::string RuTranslation);
    DictionaryNode* Delete(DictionaryNode* node, std::string EnWord);
    DictionaryNode* Search(DictionaryNode* node, std::string EnWord) const;
    DictionaryNode* FindMin(DictionaryNode* node);

    void PrintInOrder(DictionaryNode* node);
    void ClearDictionary(DictionaryNode* node);
};
#endif //LABWORK1_DICTIONARY_H