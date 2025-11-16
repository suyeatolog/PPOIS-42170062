//
// Created by user on 22.10.2025.
//

/*! \file Exhibition.h
 *  \brief Заголовочный файл с описанием класса Exhibition
 *  \details Содержит объявление класса Exhibition,
 *           который представляет выставку в музее и управляет
 *           коллекцией экспонатов, входящих в выставку.
 */
#ifndef LABWORK2_EXHIBITION_H
#define LABWORK2_EXHIBITION_H

#include <string>
#include <vector>

#include "../Exhibit/Exhibit.h"

/*! \class Exhibition
 *  \brief Класс, представляющий выставку в музее
 *  \details Класс управляет коллекцией экспонатов, объединенных общей темой.
 *           Предоставляет методы для добавления, удаления и поиска экспонатов
 *           в рамках одной выставки. Каждая выставка имеет название и тему,
 *           которые определяют ее концепцию и содержание.
 */
class Exhibition {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает пустую выставку без названия и темы
     */
    Exhibition() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Корректно удаляет объект выставки
     */
    ~Exhibition() = default;

    /*! \brief Получение названия выставки
     *  \return Название выставки
     */
    std::string GetExhibitionName() const;

    /*! \brief Получение темы выставки
     *  \return Тематическое направление выставки
     */
    std::string GetExhibitionTheme() const;

    /*! \brief Получение всех экспонатов выставки
     *  \return Вектор указателей на все экспонаты выставки
     */
    std::vector<Exhibit*> GetExhibits() const;

    /*! \brief Получение количества экспонатов на выставке
     *  \return Количество экспонатов в выставке
     */
    int GetExhibitsCount() const;

    /*! \brief Получение экспоната по индексу
     *  \param index Индекс экспоната в коллекции выставки
     *  \return Указатель на экспонат по указанному индексу или nullptr, если индекс невалидный
     */
    Exhibit* GetExhibitByIndex(int index) const;

    /*! \brief Установка названия выставки
     *  \param exhibitionName Новое название выставки
     */
    void SetExhibitionName(std::string exhibitionName);

    /*! \brief Установка темы выставки
     *  \param theme Новая тема выставки
     */
    void SetTheme(std::string theme);

    /*! \brief Добавление экспоната в выставку
     *  \param exhibit Указатель на добавляемый экспонат
     */
    void AddExhibit(Exhibit* exhibit);

    /*! \brief Удаление экспоната из выставки по индексу
     *  \param index Индекс удаляемого экспоната в коллекции
     */
    void RemoveExhibit(int index);

private:

    /*! \brief Название выставки
     *  \details Уникальное название, идентифицирующее выставку
     */
    std::string exhibitionName_;

    /*! \brief Тема выставки
     *  \details Тематическое направление, объединяющее экспонаты выставки
     */
    std::string theme_;

    /*! \brief Коллекция экспонатов
     *  \details Вектор указателей на экспонаты, входящие в выставку
     */
    std::vector<Exhibit*> exhibits_;
};

#endif //LABWORK2_EXHIBITION_H