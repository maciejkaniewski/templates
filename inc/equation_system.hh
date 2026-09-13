#ifndef EQUATION_SYSTEM_HH
#define EQUATION_SYSTEM_HH

#include "matrix.hh"

template <typename T>
class EquationSystem
{
private:
    Vector<T> B;
    Matrix<T> A;

public:
    /**
     * @brief Get the element from B vector
     *
     * @param index
     * @return T
     */
    T GetElementB(unsigned int index) const { return B[index]; }

    /**
     * @brief Change element in B vector
     *
     * @param element
     * @param index
     */
    void ChangeElementB(T element, unsigned int index) { B[index] = element; }

    /**
     * @brief Access selected row from matrix A
     *
     * @param row
     * @return Vector<T>
     */
    Vector<T> operator[](unsigned int row) const { return A[row]; }

    /**
     * @brief Modify selected row from matrix A
     *
     * @param row
     * @return Vector<T>&
     */
    Vector<T> &operator[](unsigned int row) { return A[row]; }

    /**
     * @brief Solve equation
     *
     * @return Vector<T> results
     */
    Vector<T> SolveEquation();
};

template <typename T>
Vector<T> EquationSystem<T>::SolveEquation()
{
    T tmp_det;
    T main_det;
    Vector<T> result, tmp_vector;
    Matrix<T> tmp_matrix;

    tmp_det = 0;
    main_det = 0;

    A.Transpose();
    tmp_matrix = A;
    main_det = tmp_matrix.CalculateDeterminant(tmp_matrix, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        tmp_vector = A[i];
        A[i] = B;
        tmp_matrix = A;
        tmp_det = tmp_matrix.CalculateDeterminant(tmp_matrix, SIZE);
        result[i] = tmp_det / main_det;
        A[i] = tmp_vector;
    }

    std::cout << "Solution x = (";

    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            std::cout << result[i] << ")";
        }
        else
        {
            std::cout << result[i] << ", ";
        }
    }

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const EquationSystem<T> &equation_system)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (i == (SIZE / 2))
        {
            output << "| " << equation_system[i] << "| * |x_" << i + 1 << "| = | " << equation_system.GetElementB(i) << " |" << std::endl;
        }
        else
        {
            output << "| " << equation_system[i] << "|   |x_" << i + 1 << "|   | " << equation_system.GetElementB(i) << " |" << std::endl;
        }
    }

    return output;
}

template <typename T>
std::istream &operator>>(std::istream &input, EquationSystem<T> &equation_system)
{
    Vector<T> tmp;
    T element;
    element = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        input >> tmp;
        equation_system[i] = tmp;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        input >> element;
        equation_system.ChangeElementB(element, i);
    }

    return input;
}

#endif // EQUATION_SYSTEM_H