#ifndef COMPLEX_NUMBER_HH
#define COMPLEX_NUMBER_HH

#include <iostream>
#include <cmath>

/**
 * @brief Model the concept of a complex number
 *
 */
struct ComplexNumber
{
    double real;
    double imag;

    ComplexNumber &operator=(const double &real)
    {
        this->real = real;
        this->imag = 0;
        return *this;
    }
};

/**
 * @brief Add two complex numbers
 *
 * @param number_1 first complex number
 * @param number_2 second complex number
 * @return ComplexNumber result
 */
ComplexNumber operator+(const ComplexNumber &number_1, const ComplexNumber &number_2);

/**
 * @brief Subtract two complex numbers
 *
 * @param number_1 first complex number
 * @param number_2 second complex number
 * @return ComplexNumber result
 */
ComplexNumber operator-(const ComplexNumber &number_1, const ComplexNumber &number_2);

/**
 * @brief Multiply two complex numbers
 *
 * @param number_1 first complex number
 * @param number_2 second complex number
 * @return ComplexNumber result
 */
ComplexNumber operator*(const ComplexNumber &number_1, const ComplexNumber &number_2);

/**
 * @brief Multiply complex number by number
 *
 * @param number_1 double number
 * @param number_2 complex number
 * @return ComplexNumber result
 */
ComplexNumber operator*(const double &number_1, const ComplexNumber &number_2);

/**
 * @brief Divide two complex numbers
 *
 * @param number_1 first complex number
 * @param number_2 second complex number
 * @return ComplexNumber result
 */
ComplexNumber operator/(const ComplexNumber &number_1, const ComplexNumber &number_2);

/**
 * @brief Overload of += assignment operator
 *
 * @param number_1 first complex number
 * @param number_2 second complex number
 * @return ComplexNumber
 */
ComplexNumber operator+=(ComplexNumber &number_1, const ComplexNumber &number_2);

/**
 * @brief Calculate modulus of complex number
 *
 * @param number complex number
 * @return double result
 */
double Modulus(const ComplexNumber &number);

/**
 * @brief Display complex number
 *
 * @param output stream
 * @param number complex number
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &output, const ComplexNumber &number);

/**
 * @brief Allow to input complex number
 *
 * @param input stream
 * @param number complex number
 * @return std::istream&
 */
std::istream &operator>>(std::istream &input, ComplexNumber &number);

#endif // COMPLEX_NUMBER_HH