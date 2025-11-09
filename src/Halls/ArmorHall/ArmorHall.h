//
// Created by user on 31.10.2025.
//

/*! \file ArmorHall.h
 *  \brief Заголовочный файл с описанием класса ArmorHall
 *  \details Содержит объявление класса ArmorHall,
 *           который представляет зал доспехов музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_ARMORHALL_H
#define LABWORK2_ARMORHALL_H

#include "../Hall.h"
#include <string>

/*! \class ArmorHall
 *  \brief Класс, представляющий зал доспехов музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для залов доспехов:
 *           эпоху доспехов. Реализует абстрактный метод
 *           получения типа зала.
 */
class ArmorHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект зала доспехов с инициализацией полей значениями по умолчанию
     */
    ArmorHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект зала доспехов
     */
    ~ArmorHall() = default;

    /*! \brief Получение эпохи доспехов
     *  \return Эпоху доспехов зала
     */
    std::string GetArmorEra() const;

    /*! \brief Установка эпохи доспехов
     *  \param era Новая эпоха доспехов зала
     */
    void SetArmorEra(std::string era);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "ArmorHall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;

private:
    /*! \brief Эпоха доспехов
     */
    std::string armorEra_;
};

#endif //LABWORK2_ARMORHALL_H