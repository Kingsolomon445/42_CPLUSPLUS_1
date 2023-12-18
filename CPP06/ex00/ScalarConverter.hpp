#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter & operator=(const ScalarConverter & other);

    public:
        ~ScalarConverter();


        static void convert (std::string stringRep);
} ;
void fromFloat(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal);
void fromInt(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal);
void fromDouble(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal);
void fromChar(std::string strVal, char *charVal, int *intVal, float *floatVal, double *doubleVal);
#endif