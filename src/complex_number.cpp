#include "complex_number.hh"

ComplexNumber operator+(const ComplexNumber &number_1, const ComplexNumber &number_2)
{
    ComplexNumber result;

    result.real = number_1.real + number_2.real;
    result.imag = number_1.imag + number_2.imag;

    return result;
}

ComplexNumber operator-(const ComplexNumber &number_1, const ComplexNumber &number_2)
{
    ComplexNumber result;

    result.real = number_1.real - number_2.real;
    result.imag = number_1.imag - number_2.imag;

    return result;
}

ComplexNumber operator*(const ComplexNumber &number_1, const ComplexNumber &number_2)
{
    ComplexNumber result;

    result.real = number_1.real * number_2.real - number_1.imag * number_2.imag;
    result.imag = number_1.real * number_2.imag + number_1.imag * number_2.real;

    return result;
}

ComplexNumber operator*(const double &number_1, const ComplexNumber &number_2)
{
    ComplexNumber result;

    result.real = number_2.real * number_1;
    result.imag = number_2.imag * number_1;

    return result;
}

ComplexNumber operator/(const ComplexNumber &number_1, const ComplexNumber &number_2)
{
    ComplexNumber result;

    result.real = (number_1.real * number_2.real + number_1.imag * number_2.imag) / pow(Modulus(number_2), 2);
    result.imag = (number_1.imag * number_2.real - number_1.real * number_2.imag) / pow(Modulus(number_2), 2);

    return result;
}

ComplexNumber operator+=(ComplexNumber &number_1, const ComplexNumber &number_2)
{
    number_1 = number_1 + number_2;

    return number_1;
}

double Modulus(const ComplexNumber &number)
{
    return sqrt(pow(number.real, 2) + pow(number.imag, 2));
}

std::ostream &operator<<(std::ostream &output, const ComplexNumber &number)
{
    output << "(" << number.real << std::showpos << number.imag << "i)" << std::noshowpos;
    return output;
}

std::istream &operator>>(std::istream &input, ComplexNumber &number)
{
    char tmp;

    input >> tmp; // Read '('

    if (tmp != '(') // Check for '('
    {
        input.setstate(std::ios::failbit);
        return input;
    }
    else
    {
        input >> number.real;
        input >> tmp; // Read sign

        if ((tmp != '+') && (tmp != '-')) // Check sign
        {
            input.setstate(std::ios::failbit);
            return input;
        }
        else
        {
            input >> number.imag;

            if (tmp == '-')
            {
                number.imag = -(number.imag);
            }

            input >> tmp; // Read 'i' symbol

            if (tmp != 'i') // Check for 'i'
            {
                input.setstate(std::ios::failbit);
                return input;
            }
            else
            {
                input >> tmp; // Read ')'

                if (tmp != ')') // Check for ')'
                {
                    input.setstate(std::ios::failbit);
                    return input;
                }
            }
        }
    }

    return input;
}