//
// Created by Komp on 27.09.2025.
//

/*! \file DictionaryNode.h
 *  \brief Заголовочный файл с описанием класса DictionaryNode
 *  \details Содержит объявление класса DictionaryNode,
 *           который представляет узел бинарного дерева поиска
 *           для хранения пар "английское слово - русский перевод".
 */
#ifndef LABWORK1_DICTIONARYNODE_H
#define LABWORK1_DICTIONARYNODE_H

#include <string>

/*! \class DictionaryNode
 *  \brief Класс, представляющий узел бинарного дерева поиска для словаря
 *  \details Класс хранит пару "английское слово - русский перевод" и указатели
 *           на левого и правого потомков для организации бинарного дерева поиска.
 *           Узлы упорядочены по английским словам по алфавиту.
 */
class DictionaryNode {
public:

    /*! \brief Конструктор узла словаря
     *  \param EnWord Английское слово для добавления в узел
     *  \param RuWord Русский перевод соответствующего английского слова
     */
    DictionaryNode(std::string EnWord, std::string RuWord);

    /*! \brief Деструктор узла словаря
     *  \details Освобождает ресурсы, занимаемые узлом
     */
    ~DictionaryNode();

    /*! \brief Получение английского слова
     *  \return Английское слово, хранящееся в узле
     */
    std::string GetEnWord();

    /*! \brief Получение русского перевода
     *  \return Русский перевод, хранящийся в узле
     */
    std::string GetTranslation();

    /*! \brief Получение левого потомка
     *  \return Указатель на левый дочерний узел
     */
    DictionaryNode* GetLeft();

    /*! \brief Получение правого потомка
     *  \return Указатель на правый дочерний узел
     */
    DictionaryNode* GetRight();

    /*! \brief Установка английского слова
     *  \param EnWord Новое английское слово для узла
     */
    void SetEnWord(std::string EnWord);

    /*! \brief Установка русского перевода
     *  \param RuTranslation Новый русский перевод для узла
     */
    void SetTranslation(std::string RuTranslation);

    /*! \brief Установка левого потомка
     *  \param LeftNode Указатель на новый левый дочерний узел
     */
    void SetLeft(DictionaryNode* LeftNode);

    /*! \brief Установка правого потомка
     *  \param RightNode Указатель на новый правый дочерний узел
     */
    void SetRight(DictionaryNode* RightNode);

    /*! \brief Вывод информации об узле в консоль
     *  \details Отображает английское слово и его русский перевод
     */
    void PrintNode();

private:

    /*! \brief Английское слово
     *  \details Ключ для поиска в бинарном дереве
     */
    std::string EnWord_;

    /*! \brief Русский перевод
     *  \details Значение, соответствующее английскому слову
     */
    std::string RuTranslation_;

    /*! \brief Указатель на левого потомка
     *  \details Ссылается на узел с английским словом, меньшим по алфавиту
     */
    DictionaryNode* Left_;

    /*! \brief Указатель на правого потомка
     *  \details Ссылается на узел с английским словом, большим по алфавиту
     */
    DictionaryNode* Right_;
};

#endif //LABWORK1_DICTIONARYNODE_H