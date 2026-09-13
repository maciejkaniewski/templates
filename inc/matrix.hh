#ifndef MATRIX_HH
#define MATRIX_HH

#include "vector.hh"

/**
 * @brief Model the concept of matrix
 *
 */
template <typename T>
class Matrix
{
private:
    Vector<T> matrix[SIZE];

public:
    /**
     * @brief Construct matrix filled with 0
     *
     */
    Matrix();

    /**
     * @brief Access selected row from matrix
     *
     * @param row
     * @return Vector
     */
    Vector<T> operator[](unsigned int row) const { return matrix[row]; }

    /**
     * @brief Modify selected row from matrix
     *
     * @param row
     * @return Vector<T>&
     */
    Vector<T> &operator[](unsigned int row) { return matrix[row]; }

    /**
     * @brief Multiply matrix by vector
     *
     * @param vector
     * @return Vector<T>
     */
    Vector<T> operator*(const Vector<T> &vector) const;

    /**
     * @brief Transpose matrix
     *
     */
    void Transpose();

    /**
     * @brief Calculate determinant of matrix
     *
     * @return T
     */
    T CalculateDeterminant(const Matrix<T> &matrix, int n) const;
};

template <typename T>
Matrix<T>::Matrix()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T> &vector) const
{
    T tmp = 0;
    Vector<T> result;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tmp = matrix[i][j] * vector[j];
            result[i] += tmp;
        }
    }

    return result;
}

template <typename T>
void Matrix<T>::Transpose()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

template <typename T>
T Matrix<T>::CalculateDeterminant(const Matrix<T> &matrix, int n) const
{
    T determinant;
    determinant = 0;

    if (n == 1)
    {
        return matrix[0][0];
    }

    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    Matrix<T> tmp;
    int sign = 1;

    for (int i = 0; i < n; i++)
    {
        int j = 0, k = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row != 0 && col != i)
                {
                    tmp[j][k++] = matrix[row][col];
                    if (k == n - 1)
                    {
                        k = 0;
                        j++;
                    }
                }
            }
        }

        determinant += sign * matrix[0][i] * CalculateDeterminant(tmp, n - 1);
        sign = -sign;
    }

    return determinant;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Matrix<T> &matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        output << matrix[i] << " "
               << "\n";
    }

    return output;
}

template <typename T>
std::istream &operator>>(std::istream &input, Matrix<T> &matrix)
{
    Vector<T> tmp;

    for (int i = 0; i < SIZE; i++)
    {
        input >> tmp;
        matrix[i] = tmp;
    }

    return input;
}

#endif // MATRIX_HH