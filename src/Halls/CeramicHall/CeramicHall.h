//
// Created by user on 29.10.2025.
//

/*! \file CeramicHall.h
 *  \brief Заголовочный файл с описанием класса CeramicHall
 *  \details Содержит объявление класса CeramicHall,
 *           который представляет зал керамики музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_CERAMICHALL_H
#define LABWORK2_CERAMICHALL_H

#include "../Hall.h"
#include <string>

/*! \class CeramicHall
 *  \brief Класс, представляющий зал керамики музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для залов керамики:
 *           эпоху ваз. Реализует абстрактный метод
 *           получения типа зала.
 */
class CeramicHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект зала керамики с инициализацией полей значениями по умолчанию
     */
    CeramicHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект зала керамики
     */
    ~CeramicHall() = default;

    /*! \brief Получение эпохи ваз
     *  \return Эпоху ваз зала
     */
    std::string GetVaseEra() const;

    /*! \brief Установка эпохи ваз
     *  \param era Новая эпоха ваз зала
     */
    void SetVaseEra(std::string era);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "Ceramic Hall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;
private:
    /*! \brief Эпоха ваз
     */
    std::string vaseEra_;
};

#endif //LABWORK2_CERAMICHALL_H