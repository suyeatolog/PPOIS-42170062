//
// Created by user on 03.11.2025.
//

/*! \file Tour.h
 *  \brief Заголовочный файл с описанием класса Tour
 *  \details Содержит объявление класса Tour,
 *           который представляет экскурсию по музею
 *           с маршрутом по залам и списком посетителей.
 */
#ifndef LABWORK2_TOUR_H
#define LABWORK2_TOUR_H

#include <string>
#include <vector>
#include "../../Halls/Hall.h"
#include "../../Visitor/Visitor.h"

/*! \class Tour
 *  \brief Класс, представляющий экскурсию по музею
 *  \details Класс управляет экскурсией: маршрутом по залам,
 *           списком посетителей, состоянием экскурсии и
 *           предоставляет методы для управления процессом.
 */
class Tour {
    public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект экскурсии с инициализацией полей значениями по умолчанию
     */
    Tour() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект экскурсии
     */
    ~Tour() = default;

    /*! \brief Получение названия экскурсии
     *  \return Название экскурсии
     */
    std::string GetTourName() const;

    /*! \brief Получение темы экскурсии
     *  \return Тему экскурсии
     */
    std::string GetTheme() const;

    /*! \brief Получение продолжительности
     *  \return Продолжительность экскурсии в минутах
     */
    int GetDuration() const;

    /*! \brief Получение максимального количества посетителей
     *  \return Максимальное количество посетителей
     */
    int GetMaxVisitors() const;

    /*! \brief Получение маршрута экскурсии
     *  \return Вектор указателей на залы в маршруте
     */
    std::vector<Hall*> GetRoute() const;

    /*! \brief Получение списка посетителей
     *  \return Вектор указателей на посетителей экскурсии
     */
    std::vector<Visitor*> GetVisitors() const;

    /*! \brief Получение количества посетителей
     *  \return Текущее количество посетителей на экскурсии
     */
    int GetVisitorsCount() const;

    /*! \brief Получение количества залов
     *  \return Количество залов в маршруте экскурсии
     */
    int GetHallsCount() const;

    /*! \brief Проверка заполненности экскурсии
     *  \return true если экскурсия заполнена, false в противном случае
     */
    bool IsFull() const;

    /*! \brief Установка названия экскурсии
     *  \param tourName Новое название экскурсии
     */
    void SetTourName(std::string tourName);

    /*! \brief Установка темы экскурсии
     *  \param theme Новая тема экскурсии
     */
    void SetTheme(std::string theme);

    /*! \brief Установка продолжительности
     *  \param durationMinutes Новая продолжительность в минутах
     */
    void SetDuration(int durationMinutes);

    /*! \brief Установка максимального количества посетителей
     *  \param maxVisitors Новое максимальное количество посетителей
     */
    void SetMaxVisitors(int maxVisitors);

    /*! \brief Добавление зала в маршрут
     *  \param hall Указатель на добавляемый зал
     */
    void AddHall(Hall* hall);

    /*! \brief Удаление зала из маршрута
     *  \param hallNumber Номер удаляемого зала
     */
    void RemoveHall(int hallNumber);

    /*! \brief Вставка зала в маршрут
     *  \param position Позиция для вставки
     *  \param hall Указатель на вставляемый зал
     */
    void InsertHall(int position, Hall* hall);

    /*! \brief Очистка маршрута
     *  \details Удаляет все залы из маршрута экскурсии
     */
    void ClearRoute();

    /*! \brief Реверс маршрута
     *  \details Изменяет порядок залов в маршруте на противоположный
     */
    void ReverseRoute();

    /*! \brief Добавление посетителя
     *  \param visitor Указатель на добавляемого посетителя
     */
    void AddVisitor(Visitor* visitor);

    /*! \brief Удаление посетителя
     *  \param visitorName Имя удаляемого посетителя
     */
    void RemoveVisitor(std::string visitorName);

    /*! \brief Очистка списка посетителей
     *  \details Удаляет всех посетителей из экскурсии
     */
    void ClearVisitors();

    /*! \brief Начало экскурсии
     *  \details Активирует экскурсию и устанавливает текущий зал в начало маршрута
     */
    void StartTour();

    /*! \brief Переход к следующему залу
     *  \details Перемещает экскурсию к следующему залу в маршруте
     */
    void MoveToNextHall();

    /*! \brief Завершение экскурсии
     *  \details Деактивирует экскурсию и сбрасывает текущий зал
     */
    void EndTour();

    /*! \brief Получение текущего зала
     *  \return Указатель на текущий зал экскурсии
     */
    Hall* GetCurrentHall() const;

    /*! \brief Проверка активности экскурсии
     *  \return true если экскурсия активна, false в противном случае
     */
    bool IsActive() const;

    /*! \brief Получение индекса текущего зала
     *  \return Индекс текущего зала в маршруте
     */
    int GetCurrentHallIndex() const;

    private:
    /*! \brief Название экскурсии
     */
    std::string tourName_;

    /*! \brief Тема экскурсии
     */
    std::string theme_;

    /*! \brief Продолжительность экскурсии в минутах
     */
    int duration_ = 60;

    /*! \brief Максимальное количество посетителей
     */
    int maxVisitors_ = 20;

    /*! \brief Маршрут экскурсии
     */
    std::vector<Hall*> route_;

    /*! \brief Список посетителей экскурсии
     */
    std::vector<Visitor*> visitors_;

    /*! \brief Флаг активности экскурсии
     */
    bool isActive_ = false;

    /*! \brief Индекс текущего зала в маршруте
     */
    int currentHallIndex_ = 0;
};

#endif //LABWORK2_TOUR_H