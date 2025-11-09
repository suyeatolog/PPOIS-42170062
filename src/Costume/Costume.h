//
// Created by user on 30.10.2025.
//

/*! \file Costume.h
 *  \brief Заголовочный файл с описанием класса Costume
 *  \details Содержит объявление класса Costume,
 *           который представляет костюм как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_COSTUME_H
#define LABWORK2_COSTUME_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Costume
 *  \brief Класс, представляющий костюм как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для костюмов:
 *           тип костюма, материал ткани, гендерную принадлежность и размер.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Costume : public Exhibit {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает объект костюма с инициализацией полей значениями по умолчанию
     */
    Costume() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект костюма
     */
    ~Costume() = default;

    /*! \brief Получение типа костюма
     *  \return Тип или разновидность костюма
     */
    std::string GetCostumeType() const;

    /*! \brief Получение материала ткани
     *  \return Материал изготовления костюма
     */
    std::string GetFabric() const;

    /*! \brief Получение гендерной принадлежности
     *  \return Гендерную принадлежность костюма
     */
    std::string GetGender() const;

    /*! \brief Получение размера костюма
     *  \return Размер костюма
     */
    int GetSize() const;

    /*! \brief Установка типа костюма
     *  \param costumeType Новый тип костюма
     */
    void SetCostumeType(std::string costumeType);

    /*! \brief Установка материала ткани
     *  \param fabric Новый материал изготовления костюма
     */
    void SetFabric(std::string fabric);

    /*! \brief Установка гендерной принадлежности
     *  \param gender Новая гендерная принадлежность костюма
     */
    void SetGender(std::string gender);

    /*! \brief Установка размера костюма
     *  \param size Новый размер костюма
     */
    void SetSize(int size);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Costume"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

private:

    /*! \brief Тип костюма
     */
    std::string costumeType_;

    /*! \brief Материал ткани
     */
    std::string fabric_;

    /*! \brief Гендерная принадлежность
     */
    std::string gender_;

    /*! \brief Размер костюма
     */
    int size_ = 0;
};
#endif //LABWORK2_COSTUME_H