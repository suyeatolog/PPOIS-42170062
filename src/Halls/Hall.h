//
// Created by user on 22.10.2025.
//

/*! \file Hall.h
 *  \brief Заголовочный файл с описанием абстрактного базового класса Hall
 *  \details Содержит объявление абстрактного класса Hall,
 *           который представляет зал музея и служит основой
 *           для создания специализированных типов залов.
 */
#ifndef LABWORK2_HALL_H
#define LABWORK2_HALL_H

#include <string>
#include "../Exhibition/Exhibition.h"

/*! \class Hall
 *  \brief Абстрактный базовый класс для всех залов музея
 *  \details Класс предоставляет базовый интерфейс и общие свойства
 *           для всех типов залов музея. Является абстрактным классом,
 *           от которого должны наследоваться все конкретные типы залов.
 *           Реализует принцип полиморфизма через чисто виртуальный метод
 *           получения типа зала.
 */
class Hall {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает базовый зал с инициализацией полей значениями по умолчанию
     */
    Hall() = default;

    /*! \brief Виртуальный деструктор
     *  \details Обеспечивает корректное удаление объектов производных классов
     *           через указатель на базовый класс
     */
    virtual ~Hall() = default;

    /*! \brief Получение названия зала
     *  \return Название зала
     */
    std::string GetHallName() const;

    /*! \brief Получение номера зала
     *  \return Номер зала
     */
    int GetHallNumber() const;

    /*! \brief Получение площади зала
     *  \return Площадь зала в квадратных метрах
     */
    double GetHallArea() const;

    /*! \brief Получение вместимости зала
     *  \return Вместимость зала в количестве посетителей
     */
    int GetHallCapacity() const;

    /*! \brief Установка названия зала
     *  \param name Новое название зала
     */
    void SetHallName(std::string name);

    /*! \brief Установка номера зала
     *  \param number Новый номер зала
     */
    void SetHallNumber(int number);

    /*! \brief Установка площади зала
     *  \param area Новая площадь зала в квадратных метрах
     */
    void SetHallArea(double area);

    /*! \brief Установка вместимости зала
     *  \param capacity Новая вместимость зала в количестве посетителей
     */
    void SetHallCapacity(int capacity);

    /*! \brief Установка текущей выставки в зале
     *  \param exhibition Указатель на выставку для размещения в зале
     */
    void SetCurrentExhibition(Exhibition* exhibition);

    /*! \brief Получение текущей выставки в зале
     *  \return Указатель на текущую выставку в зале
     */
    Exhibition* GetCurrentExhibition() const;

    /*! \brief Проверка наличия выставки в зале
     *  \return true если в зале есть выставка, иначе false
     */
    bool HasExhibition() const;

    /*! \brief Чисто виртуальный метод получения типа зала
     *  \return Строку с названием конкретного типа зала
     *  \details Абстрактный метод, который должен быть реализован
     *           в каждом производном классе. Обеспечивает полиморфное
     *           поведение и идентификацию типа зала.
     */
    virtual std::string GetHallType() const = 0;

protected:
    /*! \brief Название зала
     */
    std::string hallName_;

    /*! \brief Номер зала
     */
    int hallNumber_ = 0;

    /*! \brief Площадь зала
     */
    double area_ = 0;

    /*! \brief Вместимость зала
     */
    int capacity_ = 0;

    /*! \brief Текущая выставка в зале
     */
    Exhibition* currentExhibition_ = nullptr;
};

#endif //LABWORK2_HALL_H