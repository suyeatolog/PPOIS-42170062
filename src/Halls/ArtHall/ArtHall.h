/*! \file ArtHall.h
*  \brief Заголовочный файл с описанием класса ArtHall
 *  \details Содержит объявление класса ArtHall,
 *           который представляет художественный зал музея
 *           и наследует от базового класса Hall.
 */
#ifndef LABWORK2_ARTHALL_H
#define LABWORK2_ARTHALL_H

#include "../Hall.h"
#include <string>

/*! \class ArtHall
 *  \brief Класс, представляющий художественный зал музея
 *  \details Класс наследует от базового класса Hall и добавляет
 *           специфические свойства, характерные для художественных залов:
 *           художественный период. Реализует абстрактный метод
 *           получения типа зала.
 */
class ArtHall : public Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект художественного зала с инициализацией полей значениями по умолчанию
     */
    ArtHall() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект художественного зала
     */
    ~ArtHall() = default;

    /*! \brief Получение художественного периода
     *  \return Художественный период зала
     */
    std::string GetArtPeriod() const;

    /*! \brief Установка художественного периода
     *  \param period Новый художественный период зала
     */
    void SetArtPeriod(std::string period);

    /*! \brief Получение типа зала
     *  \return Строку с названием типа зала "ArtHall"
     *  \details Реализация чисто виртуального метода базового класса Hall
     */
    std::string GetHallType() const override;

private:
    /*! \brief Художественный период
     */
    std::string artPeriod_;
};

#endif //LABWORK2_ARTHALL_H