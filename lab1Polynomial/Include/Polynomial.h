/*! \file Polynomial.h
 *  \brief Заголовочный файл с описанием класса polynomial
 *  \details Содержит объявление класса polynomial,
 *           который является основным классом для реализации
 *           операций над многочленом от одной переменной. Класс
 *           предоставляет методы для выполнения всех математических
 *           операций над многочленами.
 */



#ifndef LABWORK1_POLYNOMIAL_H
#define LABWORK1_POLYNOMIAL_H

#include <iostream>
#include <vector>

/*! \class Polynomial
 *  \brief Класс, представляющий математическую модель многочлена от одной переменной
 *  \details Класс предоставляет возможности создания многочленов и проведения
 *           над ними операций вычисления, сложения, вычитания, умножения, деления,
 *           вывода результата в консоль.
 */

class Polynomial {
    public:

    /*! \brief Конструктор с инициализацией параметров
     *  \param coefficients Вектор коэффициентов при разных степенях переменной многочлена
     */
    Polynomial(const std::vector<double>& coefficients = {0.0});

    /*! \brief Оператор []
     *  \details Оператор для получения коэффициента переменной определенного коэффициента
     *  \param index Индекс переменной, коэффициент которой необходимо получить
     *  \warning При введении неверного индекса будет выведено сообщение об ошибке out_of_range
     */
    double& operator[](int index);

    /*! \brief Оператор ()
     *  \details Оператор для вычисления результата при подстановке
     *           определенного числового значения вместо переменной
     *  \param x Значение переменной
     */
    double operator()(double x) const;

    /*! \brief Оператор +
     *  \details Оператор для получения многочлена - суммы двух многочленов
     *  \param OtherPolynomial Параметр для получения второго многочлена, который необходимо прибавить к первому
     *  \return Ссылка на измененный текущий объект
     */
    Polynomial operator+(const Polynomial& OtherPolynomial) const;

    /*! \brief Оператор +
     *  \details Оператор для получения многочлена - разности двух многочленов
     *  \param OtherPolynomial Параметр для получения второго многочлена, который необходимо вычесть из первого
     *  \return Ссылка на измененный текущий объект
     */
    Polynomial operator-(const Polynomial& OtherPolynomial) const;

    /*! \brief Оператор *
     *  \details Оператор для получения многочлена - произведения двух многочленов
     *  \param OtherPolynomial Параметр для получения второго многочлена, на который необходимо умножить первый
     *  \return Ссылка на измененный текущий объект
     */
    Polynomial operator*(const Polynomial& OtherPolynomial) const;

    /*! \brief Оператор /
     *  \details Оператор для получения многочлена - частного двух многочленов
     *  \param OtherPolynomial Параметр для получения второго многочлена, на который необходимо разделить первый
     *  \warning При попытке разделения на 0, будет получено исключение: invalid_argument division by zero
     *  \return Ссылка на измененный текущий объект
     */
    Polynomial operator/(const Polynomial& OtherPolynomial) const;

    /*! \brief Составной оператор +=
     *  \details Оператор для прибавления другого многочлена к текущему
     *  \param OtherPolynomial Многочлен, который прибавляется к текущему
     *  \return Ссылка на измененный текущий объект
     */
    Polynomial& operator+=(const Polynomial& OtherPolynomial);

    /*! \brief Составной оператор -=
     *  \details Оператор для вычитания другого многочлена из текущего
     *  \param OtherPolynomial Многочлен, который вычитается из текущего
     *  \return Ссылка на измененный текущий объект
     */
    Polynomial& operator-=(const Polynomial& OtherPolynomial);

    /*! \brief Составной оператор *=
     *  \details Оператор для умножения текущего многочлена на другой
     *  \param OtherPolynomial Многочлен, на который умножается текущий
     *  \return Ссылка на измененный текущий объект
     */
    Polynomial& operator*=(const Polynomial& OtherPolynomial);

    /*! \brief Составной оператор /=
     *  \details Оператор для деления текущего многочлена на другой
     *  \param OtherPolynomial Многочлен, на который делится текущий
     *  \return Ссылка на измененный текущий объект
     *  \warning При попытке деления на нулевой многочлен генерируется исключение invalid_argument
     */
    Polynomial& operator/=(const Polynomial& OtherPolynomial);

    /*! \brief Метод вывода многочлена в консоль
     *  \details Выводит многочлен в консоль
     */
    void print() const;

    /*! \brief Метод получения степени многочлена
     *  \return Степень многочлена (наибольшая степень переменной с ненулевым коэффициентом)
     */
    int getDegree() const;

private:

    /*! \brief Вектор коэффициентов многочлена
     *  \details Коэффициенты хранятся в порядке возрастания степеней
     */
    std::vector<double> PolynomialCoefficients_;
};

#endif //LABWORK1_POLYNOMIAL_H