#include <iostream>
#include "iter.hpp"

void    capitalize(std::string &str)
{
    for (int i = 0; i < (int)str.size(); i++)
    {
        str[i] = std::toupper(str[i]);
    }
}

void square(int &nb)
{
    nb*= nb;
}

int main(void)
{
    size_t arrSize = 5;
    int intArr[arrSize];
    std::string strArr[] = {"mine", "yours", "boy", "girl", "ours"};

    for (size_t i = 0; i < arrSize; i++)
    {
        intArr[i] = i * 100 / 14;
        strArr[i] = "same";
    }

    std::cout << "After calling functions...." << std::endl;
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << "int array index " << i << ": " << intArr[i] << std::endl;
        std::cout << "string array index " << i << ": " << strArr[i] << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    ::iter(intArr, arrSize, square);
    ::iter(strArr, arrSize, capitalize);

    std::cout << "After calling functions...." << std::endl;
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << "int array index " << i << ": " << intArr[i] << std::endl;
        std::cout << "string array index " << i << ": " << strArr[i] << std::endl;
    }
    return 0;
}