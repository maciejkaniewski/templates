#ifndef VECTOR_HH
#define VECTOR_HH

#define SIZE 5

#include <iostream>
#include <cmath>

/**
 * @brief Model the concept of vector
 *
 */
template <typename T>
class Vector
{
private:
    T array[SIZE];

public:
    /**
     * @brief Construct vector filled with 0
     *
     */
    Vector();

    /**
     * @brief Access selected element from vector
     *
     * @param index
     * @return T
     */
    T operator[](unsigned int index) const { return array[index]; }

    /**
     * @brief Modify selected element from vector
     *
     * @param index
     * @return T&
     */
    T &operator[](unsigned int index) { return array[index]; }

    /**
     * @brief Add two vectors
     *
     * @param other
     * @return Vector<T>
     */
    Vector<T> operator+(const Vector<T> &other) const;

    /**
     * @brief Subtract two vectors
     *
     * @param other
     * @return Vector<T>
     */
    Vector<T> operator-(const Vector<T> &other) const;

    /**
     * @brief Divide vector by number
     *
     * @param number
     * @return Vector<T>
     */
    Vector<T> operator/(const double &number) const;

    /**
     * @brief Multiply vector by number
     *
     * @param other
     * @return Vector<T>
     */
    Vector<T> operator*(const double &other) const;

    /**
     * @brief Scalar multiplication of two vectors
     *
     * @param number
     * @return T
     */
    T operator*(const Vector<T> &number) const;

    /**
     * @brief Calculate length of vector
     *
     * @return T
     */
    T CalcuateVectorLength() const;
};

template <typename T>
Vector<T>::Vector()
{
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = 0;
    }
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other) const
{
    Vector result;

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = array[i] + other[i];
    }

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &other) const
{
    Vector<T> result;

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = array[i] - other[i];
    }

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator/(const double &number) const
{
    Vector<T> result;

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = array[i] / number;
    }

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const double &number) const
{
    Vector<T> result;

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = array[i] * number;
    }

    return result;
}

template <typename T>
T Vector<T>::operator*(const Vector<T> &other) const
{
    T result = 0, tmp = 0;

    for (int i = 0; i < SIZE; i++)
    {
        tmp = other[i] * array[i];
        result += tmp;
    }

    return result;
}

template <typename T>
T Vector<T>::CalcuateVectorLength() const
{
    T result = 0;

    for (int i = 0; i < SIZE; i++)
    {
        result += pow(array[i], 2);
    }

    return sqrt(result);
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Vector<T> &vector)
{
    for (int i = 0; i < SIZE; i++)
    {
        output << vector[i] << " ";
    }

    return output;
}

template <typename T>
std::istream &operator>>(std::istream &input, Vector<T> &vector)
{
    T tmp;
    for (int i = 0; i < SIZE; i++)
    {
        input >> tmp;
        vector[i] = tmp;
    }

    return input;
}

#endif // VECTOR_HH