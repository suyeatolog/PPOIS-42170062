/*! \file CeramicVase.h
 *  \brief Заголовочный файл с описанием класса CeramicVase
 *  \details Содержит объявление класса CeramicVase,
 *           который представляет керамическую вазу как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_CERAMICVASE_H
#define LABWORK2_CERAMICVASE_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class CeramicVase
 *  \brief Класс, представляющий керамическую вазу как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для керамических ваз:
 *           узор, хрупкость и геометрические размеры.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class CeramicVase : public Exhibit {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает объект керамической вазы с инициализацией полей значениями по умолчанию
     */
    CeramicVase() = default;

    /*! \brief Деструктор по умолчанию
         *  \details Корректно удаляет объект доспеха
         */
    ~CeramicVase() = default;

    /*! \brief Получение узора вазы
     *  \return Узор или орнамент на вазе
     */
    std::string GetPattern() const;

    /*! \brief Проверка хрупкости вазы
     *  \return true если ваза хрупкая, иначе false
     */
    bool GetFragile() const;

    /*! \brief Получение длины вазы
     *  \return Длину вазы в сантиметрах
     */
    int GetLength() const;

    /*! \brief Получение ширины вазы
     *  \return Ширину вазы в сантиметрах
     */
    int GetWidth() const;

    /*! \brief Получение высоты вазы
     *  \return Высоту вазы в сантиметрах
     */
    int GetHeight() const;

    /*! \brief Установка узора вазы
     *  \param pattern Новый узор или орнамент вазы
     */
    void SetPattern(std::string pattern);

    /*! \brief Установка хрупкости вазы
     *  \param fragile Новое состояние хрупкости вазы
     */
    void SetFragile(bool fragile);

    /*! \brief Установка длины вазы
     *  \param length Новая длина вазы в сантиметрах
     */
    void SetLength(int length);

    /*! \brief Установка ширины вазы
     *  \param width Новая ширина вазы в сантиметрах
     */
    void SetWidth(int width);

    /*! \brief Установка высоты вазы
     *  \param height Новая высота вазы в сантиметрах
     */
    void SetHeight(int height);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "Ceramic Vase"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const;

private:

    /*! \brief Узор вазы
     */
    std::string pattern_;

    /*! \brief Хрупкость вазы
     */
    bool isFragile_ = true;

    /*! \brief Длина вазы
     */
    int length_ = 0;

    /*! \brief Ширина вазы
     */
    int width_ = 0;

    /*! \brief Высота вазы
     */
    int height_ = 0;
};

#endif //LABWORK2_CERAMICVASE_H