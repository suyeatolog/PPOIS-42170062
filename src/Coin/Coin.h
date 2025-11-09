/*! \file Coin.h
 *  \brief Заголовочный файл с описанием класса Coin
 *  \details Содержит объявление класса Coin,
 *           который представляет монету как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_COIN_H
#define LABWORK2_COIN_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Coin
 *  \brief Класс, представляющий монету как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для монет:
 *           металл, валюту, номинал, год чеканки, состояние, вес и диаметр.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Coin : public Exhibit {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает объект монеты с инициализацией полей значениями по умолчанию
     */
    Coin() = default;

    /*! \brief Деструктор по умолчанию
             *  \details Корректно удаляет объект доспеха
             */
    ~Coin() = default;

    /*! \brief Получение металла монеты
     *  \return Металл изготовления монеты
     */
    std::string GetMetal() const;

    /*! \brief Получение валюты монеты
     *  \return Валютную систему монеты
     */
    std::string GetCurrency() const;

    /*! \brief Получение номинала монеты
     *  \return Номинал монеты
     */
    int GetDenomination() const;

    /*! \brief Получение года чеканки
     *  \return Год чеканки монеты
     */
    int GetMintYear() const;

    /*! \brief Получение состояния монеты
     *  \return Состояние сохранности монеты
     */
    std::string GetCondition() const;

    /*! \brief Получение веса монеты
     *  \return Вес монеты в граммах
     */
    double GetWeight() const;

    /*! \brief Получение диаметра монеты
     *  \return Диаметр монеты в миллиметрах
     */
    double GetDiameter() const;

    /*! \brief Установка металла монеты
     *  \param metal Новый металл изготовления монеты
     */
    void SetMetal(std::string metal);

    /*! \brief Установка валюты монеты
     *  \param currency Новая валютная система монеты
     */
    void SetCurrency(std::string currency);

    /*! \brief Установка номинала монеты
     *  \param denomination Новый номинал монеты
     */
    void SetDenomination(int denomination);

    /*! \brief Установка года чеканки
     *  \param year Новый год чеканки монеты
     */
    void SetMintYear(int year);

    /*! \brief Установка состояния монеты
     *  \param condition Новое состояние сохранности монеты
     */
    void SetCondition(std::string condition);

    /*! \brief Установка веса монеты
     *  \param weight Новый вес монеты в граммах
     */
    void SetWeight(double weight);

    /*! \brief Установка диаметра монеты
     *  \param diameter Новый диаметр монеты в миллиметрах
     */
    void SetDiameter(double diameter);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Coin"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

private:

    /*! \brief Металл монеты
     */
    std::string metal_;

    /*! \brief Валюта монеты
     */
    std::string currency_;

    /*! \brief Номинал монеты
     */
    int denomination_ = 0;

    /*! \brief Год чеканки
     */
    int mintYear_ = 0;

    /*! \brief Состояние монеты
     */
    std::string condition_;

    /*! \brief Вес монеты
     */
    double weight_ = 0.0;

    /*! \brief Диаметр монеты
     */
    double diameter_ = 0.0;
};

#endif //LABWORK2_COIN_H