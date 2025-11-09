/*! \file Guard.h
*  \brief Заголовочный файл с описанием класса Guard
 *  \details Содержит объявление класса Guard,
 *           который представляет охранника музея,
 *           проверяющего посетителей на подозрительность.
 */
#ifndef LABWORK2_GUARD_H
#define LABWORK2_GUARD_H

#include <string>
#include "../../Visitor/Visitor.h"
#include "../TicketWindow/TicketWindow.h"

/*! \class Guard
 *  \brief Класс, представляющий охранника музея
 *  \details Класс хранит информацию об охраннике и предоставляет
 *           метод для проверки подозрительных посетителей
 *           с взаимодействием с кассой.
 */
class Guard {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект охранника с инициализацией полей значениями по умолчанию
     */
    Guard() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект охранника
     */
    ~Guard() = default;

    /*! \brief Получение имени охранника
     *  \return Имя охранника
     */
    std::string GetGuardName() const;

    /*! \brief Получение возраста охранника
     *  \return Возраст охранника
     */
    int GetGuardAge() const;

    /*! \brief Установка имени охранника
     *  \param name Новое имя охранника
     */
    void SetGuardName(std::string name);

    /*! \brief Установка возраста охранника
     *  \param age Новый возраст охранника
     */
    void SetGuardAge(int age);

    /*! \brief Проверка подозрительного посетителя
     *  \param visitor Ссылка на проверяемого посетителя
     *  \param ticketWindow Ссылка на кассу для взаимодействия
     *  \details Проверяет посетителя на подозрительность и взаимодействует
     *           с кассой
     */
    void CheckSuspiciousVisitor(Visitor& visitor, TicketWindow& ticketWindow);

private:
    /*! \brief Имя охранника
     */
    std::string guardName_;

    /*! \brief Возраст охранника
     */
    int guardAge_ = 0;
};

#endif //LABWORK2_GUARD_H