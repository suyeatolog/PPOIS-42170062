/*! \file Checkpoint.h
 *  \brief Заголовочный файл с описанием класса Checkpoint
 *  \details Содержит объявление класса Checkpoint,
 *           который представляет контрольно-пропускной пункт музея
 *           для проверки доступа посетителей.
 */
#ifndef LABWORK2_CHECKPOINT_H
#define LABWORK2_CHECKPOINT_H

#include "../../Visitor/Visitor.h"
#include "../Guard/Guard.h"
#include "../TicketWindow/TicketWindow.h"

/*! \class Checkpoint
 *  \brief Класс, представляющий контрольно-пропускной пункт музея
 *  \details Класс координирует процесс проверки доступа посетителей,
 *           взаимодействуя с охранником и кассой для обеспечения
 *           безопасности и контроля доступа в музей.
 */
class Checkpoint {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Создает объект контрольно-пропускного пункта
     */
    Checkpoint() = default;

    /*! \brief Деструктор по умолчанию
     *  \details Удаляет объект контрольно-пропускного пункта
     */
    ~Checkpoint() = default;

    /*! \brief Проверка доступа посетителя
     *  \param visitor Ссылка на проверяемого посетителя
     *  \param guard Ссылка на охранника, который проведет проверку
     *  \param ticketWindow Ссылка на кассу
     *  \details Координирует процесс проверки доступа посетителя,
     *           используя охранника для проверки подозрительности
     *           и кассу для возврата билета в случае, если посетитель небезопасен
     */
    void CheckAccess(Visitor& visitor, Guard& guard, TicketWindow& ticketWindow);
};

#endif //LABWORK2_CHECKPOINT_H