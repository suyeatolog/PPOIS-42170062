//
// Created by user on 16.10.2025.
//

/*! \file Painting.h
 *  \brief Заголовочный файл с описанием класса Painting
 *  \details Содержит объявление класса Painting,
 *           который представляет картину как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_PAINTING_H
#define LABWORK2_PAINTING_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class Painting
 *  \brief Класс, представляющий картину как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для картин:
 *           художника, стиль, материал и размеры.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class Painting : public Exhibit {
    public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект картины с инициализацией полей значениями по умолчанию
     */
    Painting() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект картины
     */
    ~Painting() = default;

    /*! \brief Получение художника
     *  \return Художника картины
     */
    std::string GetArtist() const;

    /*! \brief Получение стиля
     *  \return Стиль картины
     */
    std::string GetStyle() const;

    /*! \brief Получение материала
     *  \return Материал картины
     */
    std::string GetMaterial() const;

    /*! \brief Получение длины картины
     *  \return Длину картины в сантиметрах
     */
    int GetLength() const;

    /*! \brief Получение ширины картины
     *  \return Ширину картины в сантиметрах
     */
    int GetWidth() const;

    /*! \brief Установка художника
     *  \param artist Новый художник картины
     */
    void SetArtist(std::string artist);

    /*! \brief Установка стиля
     *  \param style Новый стиль картины
     */
    void SetStyle(std::string style);

    /*! \brief Установка материала
     *  \param material Новый материал картины
     */
    void SetMaterial(std::string material);

    /*! \brief Установка длины картины
     *  \param length Новая длина картины в сантиметрах
     */
    void SetLength(int length);

    /*! \brief Установка ширины картины
     *  \param width Новая ширина картины в сантиметрах
     */
    void SetWidth(int width);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Painting"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

    private:
    /*! \brief Художник
     */
    std::string artist_;

    /*! \brief Стиль
     */
    std::string style_;

    /*! \brief Материал
     */
    std::string material_;

    /*! \brief Длина картины
     */
    int length_ = 0;

    /*! \brief Ширина картины
     */
    int width_ = 0;
};

#endif //LABWORK2_PAINTING_H