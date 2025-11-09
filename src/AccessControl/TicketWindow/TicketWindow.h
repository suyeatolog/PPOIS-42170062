//
// Created by user on 24.10.2025.
//

/*! \file TicketWindow.h
 *  \brief Заголовочный файл с описанием класса TicketWindow
 *  \details Содержит объявление класса TicketWindow,
 *           который представляет кассу музея для продажи билетов
 *           и учета финансовых операций.
 */
#ifndef LABWORK2_TICKETWINDOW_H
#define LABWORK2_TICKETWINDOW_H

#include "../Ticket/Ticket.h"
#include "../../Visitor/Visitor.h"
#include <string>

/*! \class TicketWindow
 *  \brief Класс, представляющий кассу музея
 *  \details Класс управляет продажей билетов посетителям,
 *           отслеживает количество доступных билетов
 *           и общую выручку от продаж.
 */
class TicketWindow {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект кассы с инициализацией полей значениями по умолчанию
     */
    TicketWindow() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект кассы
     */
    ~TicketWindow() = default;

    /*! \brief Получение количества доступных билетов
     *  \return Количество доступных билетов
     */
    int GetAmountOfTickets() const;

    /*! \brief Получение общей выручки
     *  \return Общую выручку от продажи билетов
     */
    int GetTotalGain() const;

    /*! \brief Установка количества билетов
     *  \param amount Новое количество доступных билетов
     */
    void SetAmountOfTickets(int amount);

    /*! \brief Продажа билета посетителю
     *  \param visitor Ссылка на посетителя, покупающего билет
     *  \param ticket Ссылка на продаваемый билет
     *  \details Уменьшает количество доступных билетов, увеличивает общую выручку
     *           и устанавливает у посетителя статус наличия билета
     */
    void SellTicket(Visitor& visitor, Ticket& ticket);

private:
    /*! \brief Количество доступных билетов
     */
    int amountOfTickets_ = 0;

    /*! \brief Общая выручка от продажи билетов
     */
    int totalGain_ = 0;
};

#endif //LABWORK2_TICKETWINDOW_H