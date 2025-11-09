/*! \file HandmadeTowel.h
 *  \brief Заголовочный файл с описанием класса HandmadeTowel
 *  \details Содержит объявление класса HandmadeTowel,
 *           который представляет ручное полотенце как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_HANDMADETOWEL_H
#define LABWORK2_HANDMADETOWEL_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class HandmadeTowel
 *  \brief Класс, представляющий ручное полотенце как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для ручных полотенец:
 *           тип ткани, стиль вышивки, цветовую гамму, размеры и назначение.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class HandmadeTowel : public Exhibit {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект ручного полотенца с инициализацией полей значениями по умолчанию
     */
    HandmadeTowel() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект ручного полотенца
     */
    ~HandmadeTowel() = default;

    /*! \brief Получение типа ткани
     *  \return Тип ткани полотенца
     */
    std::string GetFabricType() const;

    /*! \brief Получение стиля вышивки
     *  \return Стиль вышивки полотенца
     */
    std::string GetEmbroideryStyle() const;

    /*! \brief Получение цветовой гаммы
     *  \return Цветовую гамму полотенца
     */
    std::string GetColorScheme() const;

    /*! \brief Получение длины полотенца
     *  \return Длину полотенца в сантиметрах
     */
    int GetLength() const;

    /*! \brief Получение ширины полотенца
     *  \return Ширину полотенца в сантиметрах
     */
    int GetWidth() const;

    /*! \brief Проверка декоративного назначения
     *  \return true если полотенце декоративное, иначе false
     */
    bool GetIsDecorative() const;

    /*! \brief Установка типа ткани
     *  \param fabric Новый тип ткани полотенца
     */
    void SetFabricType(std::string fabric);

    /*! \brief Установка стиля вышивки
     *  \param style Новый стиль вышивки полотенца
     */
    void SetEmbroideryStyle(std::string style);

    /*! \brief Установка цветовой гаммы
     *  \param colors Новая цветовая гамма полотенца
     */
    void SetColorScheme(std::string colors);

    /*! \brief Установка длины полотенца
     *  \param length Новая длина полотенца в сантиметрах
     */
    void SetLength(int length);

    /*! \brief Установка ширины полотенца
     *  \param width Новая ширина полотенца в сантиметрах
     */
    void SetWidth(int width);

    /*! \brief Установка декоративного назначения
     *  \param decorative Новое состояние декоративного назначения полотенца
     */
    void SetIsDecorative(bool decorative);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Handmade Towel"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

private:
    /*! \brief Тип ткани
     */
    std::string fabricType_;

    /*! \brief Стиль вышивки
     */
    std::string embroideryStyle_;

    /*! \brief Цветовая гамма
     */
    std::string colorScheme_;

    /*! \brief Длина полотенца
     */
    int length_ = 0;

    /*! \brief Ширина полотенца
     */
    int width_ = 0;

    /*! \brief Декоративное назначение
     */
    bool isDecorative_ = true;
};

#endif //LABWORK2_HANDMADETOWEL_H