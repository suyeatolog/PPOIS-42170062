//
// Created by user on 30.10.2025.
//

/*! \file JewelryHall.h
 *  \brief Заголовочный файл с описанием класса JewelryHall
 *  \details Содержит объявление класса JewelryHall,
 *           который представляет ювелирный зал музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_JEWELRYHALL_H
#define LABWORK2_JEWELRYHALL_H

#include "../Hall.h"
#include <string>

/*! \class JewelryHall
 *  \brief Класс, представляющий ювелирный зал музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для ювелирных залов:
 *           эпоху ювелирных изделий. Реализует абстрактный метод
 *           получения типа зала.
 */
class JewelryHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект ювелирного зала с инициализацией полей значениями по умолчанию
     */
    JewelryHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект ювелирного зала
     */
    ~JewelryHall() = default;

    /*! \brief Получение эпохи ювелирных изделий
     *  \return Эпоху ювелирных изделий зала
     */
    std::string GetJewelryEra() const;

    /*! \brief Установка эпохи ювелирных изделий
     *  \param era Новая эпоха ювелирных изделий зала
     */
    void SetJewelryEra(std::string era);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "Jewelry Hall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;
private:
    /*! \brief Эпоха ювелирных изделий
     */
    std::string jewelryEra_;
};

#endif //LABWORK2_JEWELRYHALL_H