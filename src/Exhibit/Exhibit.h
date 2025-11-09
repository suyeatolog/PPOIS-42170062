//
// Created by user on 16.10.2025.
//

/*! \file Exhibit.h
 *  \brief Заголовочный файл с описанием абстрактного базового класса Exhibit
 *  \details Содержит объявление абстрактного класса Exhibit,
 *           который представляет базовый экспонат музея и служит
 *           основой для создания специализированных типов экспонатов.
 */
#ifndef LABWORK2_EXHIBIT_H
#define LABWORK2_EXHIBIT_H

#include <string>

/*! \class Exhibit
 *  \brief Абстрактный базовый класс для всех экспонатов музея
 *  \details Класс предоставляет базовый интерфейс и общие свойства
 *           для всех типов экспонатов музея. Является абстрактным классом,
 *           от которого должны наследоваться все конкретные типы экспонатов.
 *           Реализует принцип полиморфизма через чисто виртуальный метод
 *           получения типа экспоната.
 */
class Exhibit {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает базовый экспонат с инициализацией полей значениями по умолчанию
     */
    Exhibit() = default;

    /*! \brief Виртуальный деструктор
     *  \details Обеспечивает корректное удаление объектов производных классов
     *           через указатель на базовый класс
     */
    virtual ~Exhibit() = default;

    /*! \brief Получение названия коллекции экспоната
     *  \return Название коллекции, к которой принадлежит экспонат
     */
    std::string GetExhibitCollection() const;

    /*! \brief Получение имени экспоната
     *  \return Уникальное имя экспоната
     */
    std::string GetExhibitName() const;

    /*! \brief Получение идентификационного номера экспоната
     *  \return Уникальный числовой идентификатор экспоната
     */
    int GetExhibitNumberId() const;

    /*! \brief Получение года создания экспоната
     *  \return Год основания экспоната
     */
    int GetExhibitFoundationYear() const;

    /*! \brief Установка названия коллекции экспоната
     *  \param exhibitCollection Новое название коллекции для экспоната
     */
    void SetExhibitCollection(std::string exhibitCollection);

    /*! \brief Установка имени экспоната
     *  \param exhibitName Новое имя для экспоната
     */
    void SetExhibitName(std::string exhibitName);

    /*! \brief Установка идентификационного номера экспоната
     *  \param number Новый уникальный числовой идентификатор экспоната
     */
    void SetExhibitNumberId(int number);

    /*! \brief Установка года создания экспоната
     *  \param year Новый год основания экспоната
     */
    void SetExhibitFoundationYear(int year);

    /*! \brief Чисто виртуальный метод получения типа экспоната
     *  \return Строка с названием конкретного типа экспоната
     *  \details Абстрактный метод, который должен быть реализован
     *           в каждом производном классе.
     */
    virtual std::string GetExhibitType() const = 0;

protected:

    /*! \brief Название коллекции
     *  \details Название музейной коллекции, к которой принадлежит экспонат
     */
    std::string collection_;

    /*! \brief Имя экспоната
     *  \details Уникальное название или имя экспоната
     */
    std::string name_;

    /*! \brief Идентификационный номер
     *  \details Уникальный числовой идентификатор для каталогизации и поиска экспоната
     */
    int numberId_ = 0;

    /*! \brief Год создания
     *  \details Год основания, создания или изготовления экспоната
     */
    int foundationYear_ = 0;
};

#endif //LABWORK2_EXHIBIT_H