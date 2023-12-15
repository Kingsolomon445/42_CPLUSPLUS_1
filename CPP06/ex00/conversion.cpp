#include "ScalarConverter.hpp"

void fromFloat(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal)
{
    std::stringstream ss;

    ss.str("");
    ss.clear();
    ss << strVal.substr(0, strVal.size()-1);
    std::cout << ss.str() << std::endl;
    ss >> *floatVal;
    *charVal = static_cast<char>(*floatVal);
    *intVal = static_cast<int>(*floatVal);
    *doubleVal = static_cast<double>(*floatVal);
}

void fromInt(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal)
{
    std::stringstream ss;

    ss << strVal;
    std::cout << ss.str() << std::endl;
    ss >> *intVal;
    *charVal = static_cast<char>(*intVal);
    *floatVal = static_cast<float>(*intVal);
    *doubleVal = static_cast<double>(*intVal);
}

void fromDouble(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal)
{
    std::stringstream ss;

    ss << strVal;
    std::cout << ss.str() << std::endl;
    ss >> *doubleVal;
    *charVal = static_cast<char>(*doubleVal);
    *intVal = static_cast<int>(*doubleVal);
    *floatVal = static_cast<float>(*doubleVal);
}
void fromChar(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal)
{
    std::stringstream ss;

    ss << strVal;
    std::cout << ss.str() << std::endl;
    ss >> *charVal;
    *intVal = static_cast<int>(*charVal);
    *floatVal = static_cast<float>(*charVal);
    *doubleVal = static_cast<double>(*charVal);
}