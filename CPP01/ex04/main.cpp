#include <string>
#include <iostream>
#include <fstream>
#include "Sed.hpp"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "Incomplete args" << std::endl;
        return (1);
    }
    Sed sedFile(argv[1]);
    if (sedFile.file.fail())
    {
        std::cout << "Couldn't open the file!" << std::endl;
        return (1);
    }
    sedFile.replace(argv[2], argv[3]);
    return 0;
}