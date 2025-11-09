//
// Created by user on 03.11.2025.
//

/*! \file TourGuide.h
 *  \brief Заголовочный файл с описанием класса TourGuide
 *  \details Содержит объявление класса TourGuide,
 *           который представляет экскурсовода музея,
 *           управляющего экскурсиями и посетителями.
 */
#ifndef LABWORK2_TOURGUIDE_H
#define LABWORK2_TOURGUIDE_H

#include <vector>
#include <string>
#include "../Tour/Tour.h"

/*! \class TourGuide
 *  \brief Класс, представляющий экскурсовода музея
 *  \details Класс управляет данными экскурсовода, его специализацией,
 *           языками, текущей экскурсией и предоставляет методы
 *           для управления экскурсиями и проверки квалификации.
 */
class TourGuide {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект экскурсовода с инициализацией полей значениями по умолчанию
     */
    TourGuide();

    /*! \brief Деструктор
     *  \details Удаляет объект экскурсовода и освобождает ресурсы
     */
    ~TourGuide();

    /*! \brief Получение имени экскурсовода
     *  \return Имя экскурсовода
     */
    std::string GetName() const;

    /*! \brief Получение идентификатора сотрудника
     *  \return Идентификатор сотрудника
     */
    int GetEmployeeId() const;

    /*! \brief Получение специализации
     *  \return Специализацию экскурсовода
     */
    std::string GetSpecialization() const;

    /*! \brief Получение опыта работы
     *  \return Опыт работы в годах
     */
    int GetExperienceYears() const;

    /*! \brief Получение списка языков
     *  \return Вектор языков, которыми владеет экскурсовод
     */
    std::vector<std::string> GetLanguages() const;

    /*! \brief Проверка доступности экскурсовода
     *  \return true если экскурсовод доступен, false если занят
     */
    bool GetIsAvailable() const;

    /*! \brief Получение количества проведенных экскурсий
     *  \return Общее количество проведенных экскурсий
     */
    int GetToursCount() const;

    /*! \brief Получение текущей экскурсии
     *  \return Указатель на текущую экскурсию или nullptr если экскурсовод свободен
     */
    Tour* GetCurrentTour() const;

    /*! \brief Установка имени экскурсовода
     *  \param tourGuideName Новое имя экскурсовода
     */
    void SetName(std::string tourGuideName);

    /*! \brief Установка идентификатора сотрудника
     *  \param id Новый идентификатор сотрудника
     */
    void SetEmployeeId(int id);

    /*! \brief Установка специализации
     *  \param specialization Новая специализация экскурсовода
     */
    void SetSpecialization(std::string specialization);

    /*! \brief Установка опыта работы
     *  \param years Новый опыт работы в годах
     */
    void SetExperienceYears(int years);

    /*! \brief Установка списка языков
     *  \param languages Новый список языков
     */
    void SetLanguages(const std::vector<std::string>& languages);

    /*! \brief Создание новой экскурсии
     *  \param tourName Название экскурсии
     *  \param theme Тема экскурсии
     */
    void CreateTour(std::string tourName, std::string theme);

    /*! \brief Начало экскурсии
     *  \details Запускает текущую экскурсию и помечает экскурсовода как занятого
     */
    void StartTour();

    /*! \brief Завершение экскурсии
     *  \details Завершает текущую экскурсию и помечает экскурсовода как доступного
     */
    void EndTour();

    /*! \brief Переход к следующему залу
     *  \details Перемещает текущую экскурсию к следующему залу в маршруте
     */
    void MoveToNextHall();

    /*! \brief Добавление зала в маршрут
     *  \param hall Указатель на добавляемый зал
     */
    void AddHallToRoute(Hall* hall);

    /*! \brief Добавление посетителя в экскурсию
     *  \param visitor Указатель на добавляемого посетителя
     */
    void AddVisitorToTour(Visitor* visitor);

    /*! \brief Добавление языка
     *  \param language Новый язык для добавления в список
     */
    void AddLanguage(std::string language);

    /*! \brief Удаление языка
     *  \param language Язык для удаления из списка
     */
    void RemoveLanguage(std::string language);

    /*! \brief Проверка владения языком
     *  \param language Язык для проверки
     *  \return true если экскурсовод владеет языком, false в противном случае
     */
    bool SpeaksLanguage(std::string language) const;

    /*! \brief Проверка возможности проведения экскурсии в зале
     *  \param hall Указатель на проверяемый зал
     *  \return true если экскурсовод может проводить экскурсию в зале, false в противном случае
     */
    bool CanGuideHall(Hall* hall) const;

    /*! \brief Расчет коэффициента успешности экскурсий
     *  \return Коэффициент успешности от 0.0 до 1.0
     */
    double CalculateTourSuccessRate() const;

private:
    /*! \brief Имя экскурсовода
     */
    std::string name_;

    /*! \brief Идентификатор сотрудника
     */
    int employeeId_ = 0;

    /*! \brief Специализация экскурсовода
     */
    std::string specialization_;

    /*! \brief Опыт работы в годах
     */
    int experienceYears_ = 0;

    /*! \brief Список языков, которыми владеет экскурсовод
     */
    std::vector<std::string> languages_;

    /*! \brief Количество завершенных экскурсий
     */
    int toursCompleted_ = 0;

    /*! \brief Количество проведенных экскурсий
     */
    int toursConducted_ = 0;

    /*! \brief Указатель на текущую экскурсию
     */
    Tour* currentTour_ = nullptr;

    /*! \brief Флаг доступности экскурсовода
     */
    bool isAvailable_ = true;
};

#endif //LABWORK2_TOURGUIDE_H