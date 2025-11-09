//
// Created by user on 25.10.2025.
//

/*! \file Visitor.h
 *  \brief Заголовочный файл с описанием класса Visitor
 *  \details Содержит объявление класса Visitor,
 *           который представляет посетителя музея
 *           с основной информацией и статусами доступа.
 */
#ifndef LABWORK2_VISITOR_H
#define LABWORK2_VISITOR_H

#include <string>

/*! \class Visitor
 *  \brief Класс, представляющий посетителя музея
 *  \details Класс хранит персональные данные посетителя,
 *           информацию о билете, статусы доступа
 *           и флаги безопасности.
 */
class Visitor {
    public:
    /*! \brief Получение имени посетителя
     *  \return Имя посетителя
     */
    std::string GetVisitorName() const;

    /*! \brief Получение возраста посетителя
     *  \return Возраст посетителя
     */
    int GetVisitorAge() const;

    /*! \brief Проверка наличия билета
     *  \return true если у посетителя есть билет, false в противном случае
     */
    bool GetVisitorHasTicket() const;

    /*! \brief Проверка доступа в музей
     *  \return true если у посетителя есть доступ в музей, false в противном случае
     */
    bool GetVisitorHasAccess() const;

    /*! \brief Проверка подозрительности посетителя
     *  \return true если посетитель помечен как подозрительный, false в противном случае
     */
    bool GetVisitorIsSuspicious() const;

    /*! \brief Проверка опасности посетителя
     *  \return true если посетитель помечен как опасный, false в противном случае
     */
    bool GetVisitorIsDangerous() const;

    /*! \brief Установка имени посетителя
     *  \param name Новое имя посетителя
     */
    void SetVisitorName(std::string name);

    /*! \brief Установка возраста посетителя
     *  \param age Новый возраст посетителя
     */
    void SetVisitorAge(int age);

    /*! \brief Установка наличия билета
     *  \param hasTicket Новый статус наличия билета
     */
    void SetVisitorHasTicket(bool hasTicket);

    /*! \brief Установка доступа в музей
     *  \param hasAccess Новый статус доступа в музей
     */
    void SetVisitorHasAccess(bool hasAccess);

    /*! \brief Установка статуса подозрительности
     *  \param isSuspicious Новый статус подозрительности
     */
    void SetVisitorIsSuspicious(bool isSuspicious);

    /*! \brief Установка статуса опасности
     *  \param isDangerous Новый статус опасности
     */
    void SetVisitorIsDangerous(bool isDangerous);

    private:
    /*! \brief Имя посетителя
     */
    std::string name_;

    /*! \brief Возраст посетителя
     */
    int age_ = 0;

    /*! \brief Наличие билета
     */
    bool hasTicket_ = false;

    /*! \brief Доступ в музей
     */
    bool hasAccessToMuseum_ = false;

    /*! \brief Статус подозрительности
     */
    bool isSuspicious_ = false;

    /*! \brief Статус опасности
     */
    bool isDangerous_ = false;
};

#endif //LABWORK2_VISITOR_H