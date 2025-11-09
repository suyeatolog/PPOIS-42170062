//
// Created by user on 29.10.2025.
//

/*! \file ArchaeologicalHall.h
 *  \brief Заголовочный файл с описанием класса ArchaeologicalHall
 *  \details Содержит объявление класса ArchaeologicalHall,
 *           который представляет археологический зал музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_ARCHAEOLOGICALHALL_H
#define LABWORK2_ARCHAEOLOGICALHALL_H

#include "../Hall.h"
#include <string>

/*! \class ArchaeologicalHall
 *  \brief Класс, представляющий археологический зал музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для археологических залов:
 *           археологическую эпоху. Реализует абстрактный метод
 *           получения типа зала.
 */
class ArchaeologicalHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект археологического зала с инициализацией полей значениями по умолчанию
     */
    ArchaeologicalHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект археологического зала
     */
    ~ArchaeologicalHall() = default;

    /*! \brief Получение археологической эпохи
     *  \return Археологическую эпоху зала
     */
    std::string GetArchaeologicalEra() const;

    /*! \brief Установка археологической эпохи
     *  \param era Новая археологическая эпоха зала
     */
    void SetArchaeologicalEra(std::string era);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "ArchaeologicalHall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;

private:
    /*! \brief Археологическая эпоха
     */
    std::string archaeologicalEra_;
};

#endif //LABWORK2_ARCHAEOLOGICALHALL_H