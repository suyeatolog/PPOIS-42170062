/*! \file HistoryHall.h
*  \brief Заголовочный файл с описанием класса HistoryHall
 *  \details Содержит объявление класса HistoryHall,
 *           который представляет исторический зал музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_HISTORYHALL_H
#define LABWORK2_HISTORYHALL_H

#include "../Hall.h"
#include <iostream>

/*! \class HistoryHall
 *  \brief Класс, представляющий исторический зал музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для исторических залов:
 *           исторический период. Реализует абстрактный метод
 *           получения типа зала.
 */
class HistoryHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект исторического зала с инициализацией полей значениями по умолчанию
     */
    HistoryHall() = default;

    /*! \brief Получение исторического периода
     *  \return Исторический период зала
     */
    std::string GetHistoricalPeriod() const;

    /*! \brief Установка исторического периода
     *  \param historicalPeriod Новый исторический период зала
     */
    void SetHistoricalPeriod(std::string historicalPeriod);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "History Hall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;
private:
    /*! \brief Исторический период
     */
    std::string HistoricalPeriod_;
};

#endif //LABWORK2_HISTORYHALL_H