//
// Created by user on 30.10.2025.
//

/*! \file Armor.h
 *  \brief Заголовочный файл с описанием класса Armor
 *  \details Содержит объявление класса Armor,
 *           который представляет доспех как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_ARMOR_H
#define LABWORK2_ARMOR_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Armor
 *  \brief Класс, представляющий доспех как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для доспехов:
 *           материал изготовления, тип доспеха, функциональность и вес.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Armor : public Exhibit {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает объект доспеха с инициализацией полей
     *           значениями по умолчанию
     */
    Armor() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Корректно удаляет объект доспеха
     */
    ~Armor() = default;

    /*! \brief Получение материала доспеха
     *  \return Материал изготовления доспеха
     */
    std::string GetArmorMaterial() const;

    /*! \brief Получение типа доспеха
     *  \return Тип или разновидность доспеха
     */
    std::string GetArmorType() const;

    /*! \brief Проверка функциональности доспеха
     *  \return true если доспех находится в боеспособном состоянии, иначе false
     */
    bool GetArmorIsFunctional() const;

    /*! \brief Получение веса доспеха
     *  \return Вес доспеха в килограммах
     */
    double GetArmorWeight() const;

    /*! \brief Установка материала доспеха
     *  \param material Новый материал изготовления доспеха
     */
    void SetArmorMaterial(std::string material);

    /*! \brief Установка типа доспеха
     *  \param type Новый тип доспеха
     */
    void SetArmorType(std::string type);

    /*! \brief Установка функциональности доспеха
     *  \param isFunctional Новое состояние функциональности доспеха
     */
    void SetArmorIsFunctional(bool isFunctional);

    /*! \brief Установка веса доспеха
     *  \param weight Новый вес доспеха в килограммах
     */
    void SetArmorWeight(double weight);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Armor"
     *  \details Реализация чисто виртуального метода базового класса Exhibit.
     *           Возвращает конкретный тип данного экспоната.
     */
    std::string GetExhibitType() const override;

private:

    /*! \brief Материал изготовления
     *  \details Материал, из которого изготовлен доспех
     */
    std::string material_;

    /*! \brief Тип доспеха
     *  \details Разновидность или классификация доспеха
     */
    std::string armorType_;

    /*! \brief Вес доспеха
     *  \details Масса доспеха в килограммах
     */
    double weight_ = 0.0;

    /*! \brief Функциональность доспеха
     *  \details Флаг, указывающий на боеспособность доспеха
     */
    bool isFunctional_ = false;
};

#endif //LABWORK2_ARMOR_H