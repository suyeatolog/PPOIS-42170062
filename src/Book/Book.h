//
// Created by user on 17.10.2025.
//

/*! \file Book.h
 *  \brief Заголовочный файл с описанием класса Book
 *  \details Содержит объявление класса Book,
 *           который представляет книгу как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_BOOK_H
#define LABWORK2_BOOK_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Book
 *  \brief Класс, представляющий книгу как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для книг:
 *           автора и количество страниц.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Book : public Exhibit {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает объект книги с инициализацией полей значениями по умолчанию
     */
    Book() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Корректно удаляет объект доспеха
     */
    ~Book() = default;

    /*! \brief Получение автора книги
     *  \return Автор книги
     */
    std::string GetAuthor() const;

    /*! \brief Получение количества страниц
     *  \return Количество страниц в книге
     */
    int GetPageAmount() const;

    /*! \brief Установка автора книги
     *  \param author Новый автор книги
     */
    void SetAuthor(std::string author);

    /*! \brief Установка количества страниц
     *  \param pageAmount Новое количество страниц в книге
     */
    void SetPageAmount(int pageAmount);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Book"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

private:

    /*! \brief Автор книги
     */
    std::string Author_;

    /*! \brief Количество страниц
     */
    int pageAmount_ = 0;
};

#endif //LABWORK2_BOOK_H