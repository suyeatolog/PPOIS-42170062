/*! \file AncientTool.h
 *  \brief Заголовочный файл с описанием класса AncientTool
 *  \details Содержит объявление класса AncientTool,
 *           который представляет древний инструмент как тип музейного экспоната
 *           и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_ANCIENTTOOL_H
#define LABWORK2_ANCIENTTOOL_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class AncientTool
 *  \brief Класс, представляющий древний инструмент как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для древних инструментов:
 *           назначение и материал изготовления. Реализует абстрактный метод
 *           получения типа экспоната.
 */
class AncientTool : public Exhibit {
public:

    /*! \brief Конструктор по умолчанию
     *  \details Создает объект древнего инструмента с инициализацией
     *           полей значениями по умолчанию
     */
    AncientTool() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Корректно удаляет объект доспеха
     */
    ~AncientTool() = default;

    /*! \brief Получение назначения инструмента
     *  \return Назначение или функция древнего инструмента
     */
    std::string GetPurpose() const;

    /*! \brief Получение материала изготовления
     *  \return Материал, из которого изготовлен инструмент
     */
    std::string GetMaterial() const;

    /*! \brief Установка назначения инструмента
     *  \param purpose Новое назначение древнего инструмента
     */
    void SetPurpose(std::string purpose);

    /*! \brief Установка материала изготовления
     *  \param material Новый материал изготовления инструмента
     */
    void SetMaterial(std::string material);

    /*! \brief Получение типа экспоната
     *  \return Строка с названием типа экспоната "AncientTool"
     *  \details Реализация чисто виртуального метода базового класса Exhibit.
     *           Возвращает конкретный тип данного экспоната.
     */
    std::string GetExhibitType() const override;

private:

    /*! \brief Назначение инструмента
     *  \details Функциональное назначение древнего инструмента
     */
    std::string purpose_;

    /*! \brief Материал изготовления
     *  \details Материал, из которого изготовлен древний инструмент
     */
    std::string material_;
};

#endif //LABWORK2_ANCIENTTOOL_H