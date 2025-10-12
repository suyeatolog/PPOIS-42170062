//
// Created by Komp on 27.09.2025.
//

#include "../Include/DictionaryNode.h"
#include <iostream>

DictionaryNode::DictionaryNode(std::string EnWord, std::string RuTranslation) {
    this->EnWord_ = EnWord;
    this->RuTranslation_ = RuTranslation;
    this-> Left_ = nullptr;
    this-> Right_ = nullptr;
}

DictionaryNode::~DictionaryNode() {

}

std::string DictionaryNode::GetEnWord() {
    return EnWord_;
}
std::string DictionaryNode::GetTranslation() {
    return RuTranslation_;
}
DictionaryNode* DictionaryNode::GetLeft() {
    return Left_;
}
DictionaryNode* DictionaryNode::GetRight() {
    return Right_;
}

void DictionaryNode::SetEnWord(std::string EnWord) {
    this->EnWord_ = EnWord;
}
void DictionaryNode::SetTranslation(std::string RuTranslation) {
    this->RuTranslation_ = RuTranslation;
}
void DictionaryNode::SetLeft(DictionaryNode* LeftNode) {
    this->Left_ = LeftNode;
}
void DictionaryNode::SetRight(DictionaryNode* RightNode) {
    this->Right_ = RightNode;
}

void DictionaryNode::PrintNode() {
    std::cout << "English word: " << EnWord_ << std::endl << "Translation: " << RuTranslation_ << std::endl;
}