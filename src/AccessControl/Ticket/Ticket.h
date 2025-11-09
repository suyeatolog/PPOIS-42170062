//
// Created by user on 24.10.2025.
//

/*! \file Ticket.h
 *  \brief Заголовочный файл с описанием класса Ticket
 *  \details Содержит объявление класса Ticket,
 *           который представляет билет в музей
 *           с основной информацией о билете.
 */
#ifndef LABWORK2_TICKET_H
#define LABWORK2_TICKET_H

#include <string>

/*! \class Ticket
 *  \brief Класс, представляющий билет в музей
 *  \details Класс хранит информацию о билете:
 *           название, номер и цену билета.
 */
class Ticket {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект билета с инициализацией полей значениями по умолчанию
     */
    Ticket() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект билета
     */
    ~Ticket() = default;

    /*! \brief Получение названия билета
     *  \return Название билета
     */
    std::string GetTicketName() const;

    /*! \brief Получение номера билета
     *  \return Номер билета
     */
    int GetTicketNumber() const;

    /*! \brief Получение цены билета
     *  \return Цену билета
     */
    int GetTicketPrice() const;

    /*! \brief Установка названия билета
     *  \param ticketName Новое название билета
     */
    void SetTicketName(std::string ticketName);

    /*! \brief Установка номера билета
     *  \param ticketNumber Новый номер билета
     */
    void SetTicketNumber(int ticketNumber);

    /*! \brief Установка цены билета
     *  \param ticketPrice Новая цена билета
     */
    void SetTicketPrice(int ticketPrice);

private:
    /*! \brief Название билета
     */
    std::string ticketName_;

    /*! \brief Номер билета
     */
    int ticketNumber_ = 0;

    /*! \brief Цена билета
     */
    int ticketPrice_ = 0;
};

#endif //LABWORK2_TICKET_H