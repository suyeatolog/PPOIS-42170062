//
// Created by user on 25.10.2025.
//

/*! \file Exceptions.h
 *  \brief Заголовочный файл с описанием классов исключений
 *  \details Содержит объявление базового класса Exception и производных
 *           классов исключений для различных модулей музейной системы.
 */
#ifndef LABWORK2_EXCEPTIONS_H
#define LABWORK2_EXCEPTIONS_H

#include <string>
#include <exception>

/*! \class Exception
 *  \brief Базовый класс для всех исключений музейной системы
 *  \details Наследует от std::exception и предоставляет общий интерфейс
 *           для обработки исключений во всех модулях системы.
 */
class Exception : public std::exception {
    public:
    /*! \brief Конструктор исключения
     *  \param message Сообщение об ошибке
     */
    explicit Exception(const char* message);

    /*! \brief Получение сообщения об ошибке
     *  \return Сообщение об ошибке
     */
    const char* what() const noexcept override;

    private:
    /*! \brief Сообщение об ошибке
     */
    std::string message_;
};

/*! \class NoTicketsAvailableException
 *  \brief Исключение отсутствия доступных билетов
 */
class NoTicketsAvailableException : public Exception {
public:
    explicit NoTicketsAvailableException(const char* message);
};

/*! \class InvalidTicketPriceException
 *  \brief Исключение невалидной цены билета
 */
class InvalidTicketPriceException : public Exception {
public:
    explicit InvalidTicketPriceException(const char* message);
};

/*! \class NoTicketException
 *  \brief Исключение отсутствия билета у посетителя
 */
class NoTicketException : public Exception {
public:
    explicit NoTicketException(const char* message);
};

/*! \class InvalidAgeException
 *  \brief Исключение невалидного возраста посетителя
 */
class InvalidAgeException : public Exception {
public:
    explicit InvalidAgeException(const char* message);
};

/*! \class EmptyNameException
 *  \brief Исключение пустого имени посетителя
 */
class EmptyNameException : public Exception {
public:
    explicit EmptyNameException(const char* message);
};

/*! \class TourException
 *  \brief Базовое исключение для модуля экскурсий
 */
class TourException : public Exception {
public:
    explicit TourException(const char* message);
};

/*! \class EmptyTourRouteException
 *  \brief Исключение пустого маршрута экскурсии
 */
class EmptyTourRouteException : public TourException {
public:
    explicit EmptyTourRouteException(const char* message);
};

/*! \class TourFullException
 *  \brief Исключение переполненной экскурсии
 */
class TourFullException : public TourException {
public:
    explicit TourFullException(const char* message);
};

/*! \class TourNotActiveException
 *  \brief Исключение неактивной экскурсии
 */
class TourNotActiveException : public TourException {
public:
    explicit TourNotActiveException(const char* message);
};

/*! \class InvalidTourParameterException
 *  \brief Исключение невалидного параметра экскурсии
 */
class InvalidTourParameterException : public TourException {
public:
    explicit InvalidTourParameterException(const char* message);
};

/*! \class TourGuideException
 *  \brief Базовое исключение для модуля экскурсоводов
 */
class TourGuideException : public Exception {
public:
    explicit TourGuideException(const char* message);
};

/*! \class TourGuideNotAvailableException
 *  \brief Исключение недоступности экскурсовода
 */
class TourGuideNotAvailableException : public TourGuideException {
public:
    explicit TourGuideNotAvailableException(const char* message);
};

/*! \class TourAlreadyInProgressException
 *  \brief Исключение уже активной экскурсии
 */
class TourAlreadyInProgressException : public TourGuideException {
public:
    explicit TourAlreadyInProgressException(const char* message);
};

/*! \class InvalidTourParametersException
 *  \brief Исключение невалидных параметров экскурсии
 */
class InvalidTourParametersException : public TourGuideException {
public:
    explicit InvalidTourParametersException(const char* message);
};

/*! \class GuideSpecializationMismatchException
 *  \brief Исключение несоответствия специализации экскурсовода
 */
class GuideSpecializationMismatchException : public TourGuideException {
public:
    explicit GuideSpecializationMismatchException(const char* message);
};

/*! \class InvalidVisitorParameterException
 *  \brief Исключение невалидного параметра посетителя
 */
class InvalidVisitorParameterException : public Exception {
    public:
    explicit InvalidVisitorParameterException(const char* message);
};

/*! \class FullParticipantsException
 *  \brief Исключение переполненного мероприятия
 */
class FullParticipantsException : public Exception {
public:
    explicit FullParticipantsException(const char* message);
};

/*! \class VisitorAlreadyRegistered
 *  \brief Исключение повторной регистрации посетителя
 */
class VisitorAlreadyRegistered : public Exception {
public:
    explicit VisitorAlreadyRegistered(const char* message);
};
#endif //LABWORK2_EXCEPTIONS_H