//
// Created by user on 06.11.2025.
//

/*! \file MuseumEvent.h
 *  \brief Заголовочный файл с описанием класса MuseumEvent
 *  \details Содержит объявление класса MuseumEvent,
 *           который представляет мероприятие в музее и управляет
 *           участниками, местом проведения и статусом мероприятия.
 */
#ifndef LABWORK2_MUSEUMEVENT_H
#define LABWORK2_MUSEUMEVENT_H

#include <vector>
#include <string>
#include "../Visitor/Visitor.h"
#include "../Halls/Hall.h"

/*! \class MuseumEvent
 *  \brief Класс, представляющий мероприятие в музее
 *  \details Класс управляет информацией о мероприятии, включая название,
 *           тип, описание, максимальное количество участников, длительность,
 *           место проведения и список зарегистрированных участников.
 *           Предоставляет методы для регистрации участников и управления
 *           статусом мероприятия.
 */
class MuseumEvent {
    public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект мероприятия с инициализацией полей значениями по умолчанию
     */
    MuseumEvent() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект мероприятия
     */
    ~MuseumEvent() = default;

    /*! \brief Получение названия мероприятия
     *  \return Название мероприятия
     */
    std::string GetEventName() const;

    /*! \brief Получение типа мероприятия
     *  \return Тип мероприятия
     */
    std::string GetEventType() const;

    /*! \brief Получение описания мероприятия
     *  \return Описание мероприятия
     */
    std::string GetEventDescription() const;

    /*! \brief Получение максимального количества участников
     *  \return Максимальное количество участников
     */
    int GetMaxParticipants() const;

    /*! \brief Получение длительности мероприятия
     *  \return Длительность мероприятия в минутах
     */
    int GetDuration() const;

    /*! \brief Получение зала проведения
     *  \return Указатель на зал проведения мероприятия
     */
    Hall* GetHall() const;

    /*! \brief Получение списка участников
     *  \return Вектор указателей на участников мероприятия
     */
    std::vector<Visitor*> GetParticipants() const;

    /*! \brief Получение количества участников
     *  \return Количество зарегистрированных участников
     */
    int CountParticipants() const;

    /*! \brief Проверка заполненности мероприятия
     *  \return true если мероприятие заполнено, иначе false
     */
    bool IsFull() const;

    /*! \brief Проверка активности мероприятия
     *  \return true если мероприятие активно, иначе false
     */
    bool IsActive() const;

    /*! \brief Установка названия мероприятия
     *  \param name Новое название мероприятия
     */
    void SetEventName(std::string name);

    /*! \brief Установка типа мероприятия
     *  \param type Новый тип мероприятия
     */
    void SetEventType(std::string type);

    /*! \brief Установка описания мероприятия
     *  \param description Новое описание мероприятия
     */
    void SetEventDescription(std::string description);

    /*! \brief Установка максимального количества участников
     *  \param amount Новое максимальное количество участников
     */
    void SetMaxParticipants(int amount);

    /*! \brief Установка длительности мероприятия
     *  \param duration Новая длительность мероприятия в минутах
     */
    void SetDuration(int duration);

    /*! \brief Установка зала проведения
     *  \param hall Указатель на новый зал проведения мероприятия
     */
    void SetHall(Hall* hall);

    /*! \brief Установка статуса активности
     *  \param isActive Новый статус активности мероприятия
     */
    void SetIsActive(bool isActive);

    /*! \brief Добавление участника
     *  \param visitor Указатель на добавляемого участника
     */
    void AddParticipant(Visitor* visitor);

    /*! \brief Удаление участника
     *  \param visitorName Имя удаляемого участника
     */
    void RemoveParticipant(std::string visitorName);

    /*! \brief Проверка регистрации участника
     *  \param visitorName Имя проверяемого участника
     *  \return true если участник зарегистрирован, иначе false
     */
    bool IsParticipantRegistered(std::string visitorName);

    /*! \brief Запуск мероприятия
     *  \details Активирует мероприятие если указан зал проведения
     */
    void StartEvent();

    /*! \brief Завершение мероприятия
     *  \details Деактивирует мероприятие
     */
    void EndEvent();

    private:
    /*! \brief Название мероприятия
     */
    std::string eventName_;

    /*! \brief Тип мероприятия
     */
    std::string eventType_;

    /*! \brief Описание мероприятия
     */
    std::string description_;

    /*! \brief Максимальное количество участников
     */
    int maxParticipants_ = 50;

    /*! \brief Длительность мероприятия
     */
    int duration_ = 60;

    /*! \brief Статус активности
     */
    bool isActive_ = false;

    /*! \brief Зал проведения
     */
    Hall* hall_ = nullptr;

    /*! \brief Список участников
     */
    std::vector<Visitor*> participants_;
};

#endif //LABWORK2_MUSEUMEVENT_H