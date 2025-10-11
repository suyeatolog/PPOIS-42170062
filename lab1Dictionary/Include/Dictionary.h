//
// Created by Komp on 27.09.2025.
//

/*! \file Dictionary.h
 *  \brief Заголовочный файл с описанием класса Dictionary
 *  \details Содержит объявление класса Dictionary,
 *           который реализует англо-русский словарь на основе
 *           бинарного дерева поиска. Обеспечивает эффективные
 *           операции добавления, удаления и поиска слов.
 */
#ifndef LABWORK1_DICTIONARY_H
#define LABWORK1_DICTIONARY_H
#include "DictionaryNode.h"
#include <string>

/*! \class Dictionary
 *  \brief Класс, реализующий англо-русский словарь на основе бинарного дерева поиска
 *  \details Класс предоставляет функциональность для работы со словарем:
 *           добавление и удаление слов, поиск переводов, изменение переводов,
 *           вывод всего словаря. Использует бинарное дерево поиска для
 *           эффективного хранения и доступа к данным.
 */
class Dictionary {
public:

    /*! \brief Конструктор словаря
     *  \details Создает пустой словарь с нулевым корнем и счетчиком слов
     */
    Dictionary();

    /*! \brief Деструктор словаря
     *  \details Освобождает всю память, занятую узлами дерева
     */
    ~Dictionary();

    /*! \brief Оператор добавления слова в словарь
     *  \param WordPair Пара "английское слово - русский перевод" для добавления
     *  \return Ссылка на текущий объект словаря для цепочки операций
     */
    Dictionary& operator+=(std::pair<std::string, std::string> WordPair);

    /*! \brief Оператор удаления слова из словаря
     *  \param EnWord Английское слово для удаления
     *  \return Ссылка на текущий объект словаря для цепочки операций
     */
    Dictionary& operator-=(std::string EnWord);

    /*! \brief Оператор поиска перевода слова
     *  \param EnWord Английское слово для поиска перевода
     *  \return Русский перевод слова или сообщение об отсутствии слова
     */
    std::string operator[](std::string EnWord) const;

    /*! \brief Метод изменения перевода слова
     *  \param EnWord Английское слово, перевод которого нужно изменить
     *  \param NewRuTranslation Новый русский перевод для слова
     */
    void ChangeTranslation(std::string EnWord, std::string NewRuTranslation);

    /*! \brief Метод вывода всего словаря в консоль
     *  \details Выводит все слова словаря в алфавитном порядке
     *           (английские слова с их переводами)
     */
    void PrintDictionary();

    /*! \brief Метод очистки словаря для загрузки из файла
     *  \details Полностью очищает словарь, освобождая всю память
     *           и сбрасывая счетчик слов. Используется перед
     *           загрузкой нового словаря из файла.
     */
    void ClearDictionaryForFile();

    /*! \brief Проверка пустоты словаря
     *  \return true если словарь пуст, false если содержит слова
     */
    bool IsEmpty();

    /*! \brief Проверка существования слова в словаре
     *  \param EnWord Английское слово для проверки
     *  \return true если слово существует в словаре, false в противном случае
     */
    bool WordExists(std::string EnWord);

    /*! \brief Получение количества слов в словаре
     *  \return Количество слов в словаре
     */
    int GetWordCount();

private:

    /*! \brief Корень бинарного дерева поиска
     *  \details Указатель на корневой узел дерева словаря
     */
    DictionaryNode* Root_;

    /*! \brief Счетчик слов в словаре
     *  \details Хранит текущее количество слов в словаре
     */
    int WordCount_;

    /*! \brief Вспомогательный метод вставки узла в дерево
     *  \param node Текущий узел дерева для рекурсивного обхода
     *  \param EnWord Английское слово для вставки
     *  \param RuTranslation Русский перевод для вставки
     *  \return Указатель на корень поддерева после вставки
     */
    DictionaryNode* Insert(DictionaryNode* node, std::string EnWord, std::string RuTranslation);

    /*! \brief Вспомогательный метод удаления узла из дерева
     *  \param node Текущий узел дерева для рекурсивного обхода
     *  \param EnWord Английское слово для удаления
     *  \return Указатель на корень поддерева после удаления
     */
    DictionaryNode* Delete(DictionaryNode* node, std::string EnWord);

    /*! \brief Вспомогательный метод поиска узла в дереве
     *  \param node Текущий узел дерева для рекурсивного обхода
     *  \param EnWord Английское слово для поиска
     *  \return Указатель на найденный узел или nullptr если слово не найдено
     */
    DictionaryNode* Search(DictionaryNode* node, std::string EnWord) const;

    /*! \brief Вспомогательный метод поиска минимального узла в поддереве
     *  \param node Корень поддерева для поиска
     *  \return Указатель на узел с минимальным значением в поддереве
     */
    DictionaryNode* FindMin(DictionaryNode* node);

    /*! \brief Вспомогательный метод вывода дерева в порядке возрастания
     *  \param node Текущий узел дерева для рекурсивного обхода
     */
    void PrintInOrder(DictionaryNode* node);

    /*! \brief Вспомогательный метод рекурсивной очистки дерева
     *  \param node Текущий узел дерева для рекурсивной очистки
     */
    void ClearDictionary(DictionaryNode* node);
};
#endif //LABWORK1_DICTIONARY_H