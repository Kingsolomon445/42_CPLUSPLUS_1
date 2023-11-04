#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    Harl harl;
    if (argc < 2)
    {
        std::cout << "Invalid args" << std::endl;
        return (1);
    }
    harl.complain(argv[1]);
    return 0;
}