#include "equation_system.hh"
#include "complex_number.hh"

int main(int argc, char **argv)
{

    char tmp;
    std::cin >> tmp;

    switch (tmp)
    {
        case 'R':
        {
            EquationSystem<double> system;
            std::cin >> system;
            std::cout << "System of equations:" << std::endl
                    << std::endl;
            std::cout << system << std::endl;
            system.SolveEquation();
        }
        break;

        case 'C':
        {
            EquationSystem<ComplexNumber> system;
            std::cin >> system;
            std::cout << "System of equations:" << std::endl
                    << std::endl;
            std::cout << system << std::endl;
            system.SolveEquation();
        }
        break;

        default:
        {
            std::cout << "No options to define the type of input data." << std::endl;
            std::cout << "Available:  R, C." << std::endl;
        }
    }
}