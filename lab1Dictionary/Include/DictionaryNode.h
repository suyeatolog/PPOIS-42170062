//
// Created by Komp on 27.09.2025.
//

#ifndef LABWORK1_DICTIONARYNODE_H
#define LABWORK1_DICTIONARYNODE_H

#include <string>

class DictionaryNode {
public:
    DictionaryNode(std::string EnWord, std::string RuWord);

    ~DictionaryNode();

    std::string GetEnWord();
    std::string GetTranslation();
    DictionaryNode* GetLeft();
    DictionaryNode* GetRight();

    void SetEnWord(std::string EnWord);
    void SetTranslation(std::string RuTranslation);
    void SetLeft(DictionaryNode* LeftNode);
    void SetRight(DictionaryNode* RightNode);

    void PrintNode();

private:
    std::string EnWord_;
    std::string RuTranslation_;

    DictionaryNode* Left_;
    DictionaryNode* Right_;

};

#endif //LABWORK1_DICTIONARYNODE_H