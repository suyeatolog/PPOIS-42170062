//
// Created by user on 29.10.2025.
//

/*! \file WarHall.h
 *  \brief Заголовочный файл с описанием класса WarHall
 *  \details Содержит объявление класса WarHall,
 *           который представляет военный зал музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_WARHALL_H
#define LABWORK2_WARHALL_H

#include "../Hall.h"
#include <string>

/*! \class WarHall
 *  \brief Класс, представляющий военный зал музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для военных залов:
 *           название войны. Реализует абстрактный метод
 *           получения типа зала.
 */
class WarHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект военного зала с инициализацией полей значениями по умолчанию
     */
    WarHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект военного зала
     */
    ~WarHall() = default;

    /*! \brief Получение названия войны
     *  \return Название войны зала
     */
    std::string GetWarName() const;

    /*! \brief Установка названия войны
     *  \param name Новое название войны зала
     */
    void SetWarName(std::string name);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "War Hall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;
private:
    /*! \brief Название войны
     */
    std::string warName_;
};

#endif //LABWORK2_WARHALL_H