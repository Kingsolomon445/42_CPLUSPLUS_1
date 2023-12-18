#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
    static_cast<void>(other);
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
    static_cast<void>(other);
    return *this;
}

ScalarConverter::~ScalarConverter() {}

int checkType(std::string str)
{
    int dotCount = 0;
    int fFound = 0;
    if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
        return 2;
    else if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
        return 3;
    if (str[0] == '.' && (str[1] == 'f' || str[1] == 'F'))
        return 0;
    if ((int)str.size() == 1 && (str[0] < 48 || str[0] > 57))
        return 4;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] < 48 || str[i] > 57)
        {
            if (str[i] == '.')
                dotCount++;
            else if (i == (int)str.size() - 1 && (str[i] == 'f' || str[1] == 'F') && !fFound)
                fFound = 1;
            else if ((str[i] == '-' || str[i] == '+') && i == 0)
                continue;
            else
                return 0;
        }
    }
    if (fFound && dotCount <= 1)
        return 2;
    else if (dotCount == 1)
        return 3;
    else if (!dotCount && !fFound)
        return 1;
    else
        return 0;
}


void ScalarConverter::convert(std::string stringRep)
{
    std::stringstream ss;
    int checker = checkType(stringRep);
    int intVal = 1;
    float floatVal = 1.0f;
    double doubleVal = 1.0;
    char charVal = '\0';

    ss << stringRep;
    if (checker == 1)
        fromInt(stringRep, &charVal, &intVal, &floatVal, &doubleVal);
    else if (checker == 2)
        fromFloat(stringRep, &charVal, &intVal, &floatVal, &doubleVal);
    else if (checker == 3)
        fromDouble(stringRep, &charVal, &intVal, &floatVal, &doubleVal);
    else if (checker == 4)
        fromChar(stringRep, &charVal, &intVal, &floatVal, &doubleVal);
    else
    {
        std::cout << "Type conversion is not possible for the value: " << stringRep << std::endl;
        return ;
    }
    if (intVal < 0)
        std::cout << "char: impossible" << std::endl;
    else if (intVal < 32 || intVal > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << charVal << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (intVal == -2147483648)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << intVal << std::endl;
    std::cout << "float: " << floatVal << "f" << std::endl;
    std::cout << "double: "  << doubleVal << std::endl;
}