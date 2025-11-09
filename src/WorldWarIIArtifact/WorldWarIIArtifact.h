/*! \file WorldWarIIArtifact.h
 *  \brief Заголовочный файл с описанием класса WorldWarIIArtifact
 *  \details Содержит объявление класса WorldWarIIArtifact,
 *           который представляет артефакт Второй мировой войны
 *           как тип музейного экспоната и наследует от базового класса Exhibit.
 */
#ifndef LABWORK2_WORLDWARIIARTIFACT_H
#define LABWORK2_WORLDWARIIARTIFACT_H

#include "../Exhibit/Exhibit.h"
#include <string>

/*! \class WorldWarIIArtifact
 *  \brief Класс, представляющий артефакт Второй мировой войны как музейный экспонат
 *  \details Класс наследует от базового класса Exhibit и добавляет
 *           специфические свойства, характерные для артефактов Второй мировой войны:
 *           тип артефакта, состояние, боевая история и страна происхождения.
 *           Реализует абстрактный метод получения типа экспоната.
 */
class WorldWarIIArtifact : public Exhibit {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект артефакта с инициализацией полей значениями по умолчанию
     */
    WorldWarIIArtifact() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект скульптуры
     */
    ~WorldWarIIArtifact() = default;

    /*! \brief Получение типа артефакта
     *  \return Тип артефакта Второй мировой войны
     */
    std::string GetArtifactType() const;

    /*! \brief Получение состояния артефакта
     *  \return Состояние сохранности артефакта
     */
    std::string GetCondition() const;

    /*! \brief Проверка боевой истории
     *  \return true если артефакт имеет боевую историю, false в противном случае
     */
    bool GetHasCombatHistory() const;

    /*! \brief Получение страны происхождения
     *  \return Страну происхождения артефакта
     */
    std::string GetOriginCountry() const;

    /*! \brief Установка типа артефакта
     *  \param artifactType Новый тип артефакта
     */
    void SetArtifactType(std::string artifactType);

    /*! \brief Установка состояния артефакта
     *  \param condition Новое состояние сохранности артефакта
     */
    void SetCondition(std::string condition);

    /*! \brief Установка наличия боевой истории
     *  \param hasCombatHistory Новый статус боевой истории
     */
    void SetHasCombatHistory(bool hasCombatHistory);

    /*! \brief Установка страны происхождения
     *  \param originCountry Новая страна происхождения артефакта
     */
    void SetOriginCountry(std::string originCountry);

    /*! \brief Получение типа экспоната
     *  \return Строку с названием типа экспоната "WorldWarIIArtifact"
     *  \details Реализация чисто виртуального метода базового класса Exhibit
     */
    std::string GetExhibitType() const override;

private:
    /*! \brief Тип артефакта
     */
    std::string artifactType_;

    /*! \brief Состояние сохранности
     */
    std::string condition_;

    /*! \brief Наличие боевой истории
     */
    bool hasCombatHistory_ = false;

    /*! \brief Страна происхождения
     */
    std::string originCountry_;
};

#endif //LABWORK2_WORLDWARIIARTIFACT_H