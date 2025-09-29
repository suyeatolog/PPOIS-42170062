//
// Created by Komp on 27.09.2025.
//
#include "../Include/Dictionary.h"
#include <iostream>

Dictionary::Dictionary() {
    Root_ = nullptr;
    WordCount_ =  0;
}

Dictionary::~Dictionary() {
    ClearDictionary(Root_);
}

void Dictionary::ClearDictionary(DictionaryNode* Root) {
    if (Root != nullptr) {
        ClearDictionary(Root->GetLeft());
        ClearDictionary(Root->GetRight());
        delete Root;
    }
}

void Dictionary::ClearDictionaryForFile() {
    ClearDictionary(Root_);
    Root_ = nullptr;
    WordCount_ =  0;
}


DictionaryNode* Dictionary::Insert(DictionaryNode* Node, std::string EnWord, std::string RuTranslation) {
    if (Node == nullptr) {
        WordCount_++;
        return new DictionaryNode(EnWord, RuTranslation);
    }
    if (EnWord < Node->GetEnWord()) {
        Node->SetLeft(Insert(Node->GetLeft(), EnWord, RuTranslation));
    }
    else if (EnWord > Node->GetEnWord()) {
        Node->SetRight(Insert(Node->GetRight(), EnWord, RuTranslation));
    }
    else {
        Node->SetTranslation(RuTranslation);
    }
    return Node;
}

Dictionary& Dictionary::operator+=(std::pair<std::string, std::string> WordPair) {
    this->Root_ = Insert(this->Root_, WordPair.first, WordPair.second);
    return *this;
}

DictionaryNode* Dictionary::FindMin(DictionaryNode* node) {
    while (node != nullptr && node->GetLeft() != nullptr) {
        node = node->GetLeft();
    }
    return node;
}

DictionaryNode* Dictionary::Delete(DictionaryNode* node, std::string EnWord) {
    if (node == nullptr) return nullptr;

    if (EnWord < node->GetEnWord()) {
        node->SetLeft(Delete(node->GetLeft(), EnWord));
    }
    else if (EnWord > node->GetEnWord()) {
        node->SetRight(Delete(node->GetRight(), EnWord));
    }
    else {
        if (node->GetLeft() == nullptr) {
            DictionaryNode* temp = node->GetRight();
            delete node;
            WordCount_--;
            return temp;
        }
        else if (node->GetRight() == nullptr) {
            DictionaryNode* temp = node->GetLeft();
            delete node;
            WordCount_--;
            return temp;
        }
        else {
            DictionaryNode* temp = FindMin(node->GetRight());
            node->SetEnWord(temp->GetEnWord());
            node->SetTranslation(temp->GetTranslation());
            node->SetRight(Delete(node->GetRight(), temp->GetEnWord()));
        }
    }
    return node;
}

Dictionary& Dictionary::operator-=(std::string EnWord) {
    this->Root_ = Delete(this->Root_, EnWord);
    return *this;
}

DictionaryNode* Dictionary::Search(DictionaryNode* node, std::string EnWord) const {
    if (node == nullptr || node->GetEnWord() == EnWord) {
        return node;
    }
    if (EnWord < node->GetEnWord()) {
        return Search(node->GetLeft(), EnWord);
    }
    else {
        return Search(node->GetRight(), EnWord);
    }
}

std::string Dictionary::operator[](std::string EnWord) const {
    DictionaryNode* Node = Search(this->Root_, EnWord);
    if (Node != nullptr) {
        return Node->GetTranslation();
    }
    else {
        return "The word You are looking for seems to be missing in this dictionary.";
    }
}

void Dictionary::ChangeTranslation(std::string EnWord, std::string NewRuTranslation) {
    DictionaryNode* Node = Search(this->Root_, EnWord);
    if (Node != nullptr) {
        Node->SetTranslation(NewRuTranslation);
        std::cout << "Translation for word " << EnWord << " is updated! It's " << NewRuTranslation << " now!" << std::endl;
    }
    else {
        std::cout << "Cannot change translation: word " << EnWord << " seems to be missing in this dictionary!" << std::endl;
    }
}

int Dictionary::GetWordCount() {
    return WordCount_;
}

void Dictionary::PrintInOrder(DictionaryNode* node) {
    if (node != nullptr) {
        PrintInOrder(node->GetLeft());
        node->PrintNode();
        PrintInOrder(node->GetRight());
    }
}

void Dictionary::PrintDictionary() {
    std::cout << "This dictionary:" << std::endl;
    if (Root_ != nullptr) {
        PrintInOrder(Root_);
    }
    else {
        std::cout << "This dictionary is empty." << std::endl;
    }
}

bool Dictionary::WordExists(std::string EnWord) {
    DictionaryNode* Node = Search(this->Root_, EnWord);
    return Node != nullptr;
}

bool Dictionary::IsEmpty() {
    return Root_ == nullptr;
}