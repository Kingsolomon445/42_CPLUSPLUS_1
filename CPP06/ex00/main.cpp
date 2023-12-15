#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments!";
        return 1;
    }
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}
