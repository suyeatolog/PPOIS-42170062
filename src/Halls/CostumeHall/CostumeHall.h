//
// Created by user on 31.10.2025.
//

/*! \file CostumeHall.h
 *  \brief Заголовочный файл с описанием класса CostumeHall
 *  \details Содержит объявление класса CostumeHall,
 *           который представляет зал костюмов музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_COSTUMEHALL_H
#define LABWORK2_COSTUMEHALL_H

#include "../Hall.h"
#include <string>

/*! \class CostumeHall
 *  \brief Класс, представляющий зал костюмов музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для залов костюмов:
 *           эпоху костюмов. Реализует абстрактный метод
 *           получения типа зала.
 */
class CostumeHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект зала костюмов с инициализацией полей значениями по умолчанию
     */
    CostumeHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект зала костюмов
     */
    ~CostumeHall() = default;

    /*! \brief Получение эпохи костюмов
     *  \return Эпоху костюмов зала
     */
    std::string GetCostumeEra() const;

    /*! \brief Установка эпохи костюмов
     *  \param era Новая эпоха костюмов зала
     */
    void SetCostumeEra(std::string era);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "Costume Hall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;
private:
    /*! \brief Эпоха костюмов
     */
    std::string costumeEra_;
};

#endif //LABWORK2_COSTUMEHALL_H