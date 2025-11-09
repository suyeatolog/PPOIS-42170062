//
// Created by user on 16.10.2025.
//

/*! \file Sculpture.h
 *  \brief Заголовочный файл с описанием класса Sculpture
 *  \details Содержит объявление класса Sculpture,
 *           который представляет скульптуру как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_SCULPTURE_H
#define LABWORK2_SCULPTURE_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Sculpture
 *  \brief Класс, представляющий скульптуру как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для скульптур:
 *           скульптора, материал, вес, хрупкость и размеры.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Sculpture : public Exhibit {
    public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект скульптуры с инициализацией полей значениями по умолчанию
     */
    Sculpture() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект скульптуры
     */
    ~Sculpture() = default;

    /*! \brief Получение скульптора
     *  \return Скульптора скульптуры
     */
    std::string GetSculpturist() const;

    /*! \brief Получение материала
     *  \return Материал скульптуры
     */
    std::string GetMaterial() const;

    /*! \brief Получение веса
     *  \return Вес скульптуры в килограммах
     */
    double GetWeight() const;

    /*! \brief Проверка хрупкости
     *  \return true если скульптура хрупкая, false в противном случае
     */
    bool IsFragile() const;

    /*! \brief Получение длины скульптуры
     *  \return Длину скульптуры в сантиметрах
     */
    int GetLength() const;

    /*! \brief Получение ширины скульптуры
     *  \return Ширину скульптуры в сантиметрах
     */
    int GetWidth() const;

    /*! \brief Получение высоты скульптуры
     *  \return Высоту скульптуры в сантиметрах
     */
    int GetHeight() const;

    /*! \brief Установка скульптора
     *  \param sculpturist Новый скульптор скульптуры
     */
    void SetSculpturist(std::string sculpturist);

    /*! \brief Установка материала
     *  \param material Новый материал скульптуры
     */
    void SetMaterial(std::string material);

    /*! \brief Установка веса
     *  \param weight Новый вес скульптуры в килограммах
     */
    void SetWeight(double weight);

    /*! \brief Установка хрупкости
     *  \param isFragile Новая хрупкость скульптуры
     */
    void SetFragile(bool isFragile);

    /*! \brief Установка длины скульптуры
     *  \param length Новая длина скульптуры в сантиметрах
     */
    void SetLength(int length);

    /*! \brief Установка ширины скульптуры
     *  \param width Новая ширина скульптуры в сантиметрах
     */
    void SetWidth(int width);

    /*! \brief Установка высоты скульптуры
     *  \param height Новая высота скульптуры в сантиметрах
     */
    void SetHeight(int height);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Sculpture"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

    private:
    /*! \brief Скульптор
     */
    std::string sculpturist_;

    /*! \brief Материал
     */
    std::string material_;

    /*! \brief Вес скульптуры в килограммах
     */
    double weight_ = 0.0;

    /*! \brief Хрупкость скульптуры
     */
    bool isFragile_ = false;

    /*! \brief Длина скульптуры в сантиметрах
     */
    int length_ = 0;

    /*! \brief Ширина скульптуры в сантиметрах
     */
    int width_ = 0;

    /*! \brief Высота скульптуры в сантиметрах
     */
    int height_ = 0;
};

#endif //LABWORK2_SCULPTURE_H