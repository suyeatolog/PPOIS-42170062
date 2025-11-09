//
// Created by user on 17.10.2025.
//

/*! \file Fossil.h
 *  \brief Заголовочный файл с описанием класса Fossil
 *  \details Содержит объявление класса Fossil,
 *           который представляет окаменелость как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_FOSSIL_H
#define LABWORK2_FOSSIL_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Fossil
 *  \brief Класс, представляющий окаменелость как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для окаменелостей:
 *           вид организма, место находки, количество костей, вес и размеры.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Fossil : public Exhibit {
    public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект окаменелости с инициализацией полей значениями по умолчанию
     */
    Fossil() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект окаменелости
     */
    ~Fossil() = default;

    /*! \brief Получение вида организма
     *  \return Вид организма окаменелости
     */
    std::string GetSpecies() const;

    /*! \brief Получение места находки
     *  \return Место обнаружения окаменелости
     */
    std::string GetFoundationPlace() const;

    /*! \brief Получение количества костей
     *  \return Количество костей в окаменелости
     */
    int GetBoneAmount() const;

    /*! \brief Получение веса окаменелости
     *  \return Вес окаменелости в килограммах
     */
    double GetWeight() const;

    /*! \brief Получение длины окаменелости
     *  \return Длину окаменелости в сантиметрах
     */
    int GetLength() const;

    /*! \brief Получение ширины окаменелости
     *  \return Ширину окаменелости в сантиметрах
     */
    int GetWidth() const;

    /*! \brief Получение высоты окаменелости
     *  \return Высоту окаменелости в сантиметрах
     */
    int GetHeight() const;

    /*! \brief Установка вида организма
     *  \param species Новый вид организма окаменелости
     */
    void SetSpecies(std::string species);

    /*! \brief Установка места находки
     *  \param place Новое место обнаружения окаменелости
     */
    void SetFoundationPlace(std::string place);

    /*! \brief Установка количества костей
     *  \param bone Новое количество костей в окаменелости
     */
    void SetBoneAmount(int bone);

    /*! \brief Установка веса окаменелости
     *  \param weight Новый вес окаменелости в килограммах
     */
    void SetWeight(double weight);

    /*! \brief Установка длины окаменелости
     *  \param length Новая длина окаменелости в сантиметрах
     */
    void SetLength(int length);

    /*! \brief Установка ширины окаменелости
     *  \param width Новая ширина окаменелости в сантиметрах
     */
    void SetWidth(int width);

    /*! \brief Установка высоты окаменелости
     *  \param height Новая высота окаменелости в сантиметрах
     */
    void SetHeight(int height);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Fossil"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

private:
    /*! \brief Вид организма
     */
    std::string species_;

    /*! \brief Место находки
     */
    std::string foundationPlace_;

    /*! \brief Количество костей
     */
    int boneAmount_ = 0;

    /*! \brief Вес окаменелости
     */
    double weight_ = 0.0;

    /*! \brief Длина окаменелости
     */
    int length_ = 0;

    /*! \brief Ширина окаменелости
     */
    int width_ = 0;

    /*! \brief Высота окаменелости
     */
    int height_ = 0;
};

#endif //LABWORK2_FOSSIL_H