//
// Created by user on 30.10.2025.
//

/*! \file Jewelry.h
 *  \brief Заголовочный файл с описанием класса Jewelry
 *  \details Содержит объявление класса Jewelry,
 *           который представляет ювелирное изделие как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_JEWERLY_H
#define LABWORK2_JEWERLY_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Jewelry
 *  \brief Класс, представляющий ювелирное изделие как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для ювелирных изделий:
 *           материал, драгоценный камень, тип изделия и вес.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Jewelry : public Exhibit {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект ювелирного изделия с инициализацией полей значениями по умолчанию
     */
    Jewelry() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект ювелирного изделия
     */
    ~Jewelry() = default;

    /*! \brief Получение материала изделия
     *  \return Материал ювелирного изделия
     */
    std::string GetJewelryMaterial() const;

    /*! \brief Получение драгоценного камня
     *  \return Драгоценный камень изделия
     */
    std::string GetJewelryGemstone() const;

    /*! \brief Получение типа изделия
     *  \return Тип ювелирного изделия
     */
    std::string GetJewelryType() const;

    /*! \brief Получение веса изделия
     *  \return Вес ювелирного изделия в граммах
     */
    double GetJewelryWeight() const;

    /*! \brief Установка материала изделия
     *  \param material Новый материал ювелирного изделия
     */
    void SetJewelryMaterial(std::string material);

    /*! \brief Установка драгоценного камня
     *  \param gemstone Новый драгоценный камень изделия
     */
    void SetJewelryGemstone(std::string gemstone);

    /*! \brief Установка типа изделия
     *  \param type Новый тип ювелирного изделия
     */
    void SetJewelryType(std::string type);

    /*! \brief Установка веса изделия
     *  \param weight Новый вес ювелирного изделия в граммах
     */
    void SetJewelryWeight(double weight);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Jewelry"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;
private:
    /*! \brief Материал изделия
     */
    std::string material_;

    /*! \brief Драгоценный камень
     */
    std::string gemstone_;

    /*! \brief Тип изделия
     */
    std::string jewelryType_;

    /*! \brief Вес изделия
     */
    double weight_ = 0.0;
};

#endif //LABWORK2_JEWERLY_H