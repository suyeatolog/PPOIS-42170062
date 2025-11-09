//
// Created by user on 29.10.2025.
//

/*! \file NumismaticsHall.h
 *  \brief Заголовочный файл с описанием класса NumismaticsHall
 *  \details Содержит объявление класса NumismaticsHall,
 *           который представляет нумизматический зал музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_NUMISMATICSHALL_H
#define LABWORK2_NUMISMATICSHALL_H

#include "../Hall.h"
#include <string>

/*! \class NumismaticsHall
 *  \brief Класс, представляющий нумизматический зал музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для нумизматических залов:
 *           эпоху монет. Реализует абстрактный метод
 *           получения типа зала.
 */
class NumismaticsHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект нумизматического зала с инициализацией полей значениями по умолчанию
     */
    NumismaticsHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект нумизматического зала
     */
    ~NumismaticsHall() = default;

    /*! \brief Получение эпохи монет
     *  \return Эпоху монет зала
     */
    std::string GetCoinEra() const;

    /*! \brief Установка эпохи монет
     *  \param coinEra Новая эпоха монет зала
     */
    void SetCoinEra(std::string coinEra);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "Numismatics Hall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;
private:
    /*! \brief Эпоха монет
     */
    std::string coinEra_;
};

#endif //LABWORK2_NUMISMATICSHALL_H